#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#include "terminal.h"
#include "highlight.h"
#include "row.h"
#include "editor.h"

struct Editor E;

void die(const char *s) {
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);

    perror(s);
    exit(1);
}


void EditorInit() {
    E.cx = 0;
    E.cy = 0;
    E.rx = 0;
    E.rowoff = 0;
    E.coloff = 0;
    E.numrows = 0;
    E.row = NULL;
    E.dirty = 0;
    E.filename = NULL;
    E.statusmsg[0] = '\0';
    E.statusmsg_time = 0;
    E.syntax = NULL;

    if(TerminalGetWindowSize(&E.screenrows, &E.screencols) == -1) die("TerminalGetWindowSize");
    E.screenrows -= 2;
}

void EditorOpen(char *filename) {
    free(E.filename);
    E.filename = strdup(filename);

    HighlightSyntax();

    FILE *fp = fopen(filename, "r");
    if(!fp) die("fopen");

    char* line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    
    while((linelen = getline(&line, &linecap, fp)) != -1) {
        while(linelen > 0 && (line[linelen-1] == '\n' || line[linelen-1] == '\r'))
            linelen--;
        EditorInsertRow(E.numrows, line, linelen);
    }
    free(line);
    fclose(fp);
    E.dirty = 0;
}

void EditorSave() {
    if(E.filename == NULL) {
        E.filename = EditorPrompt("Save as: %s (ESC to cancel)", NULL);
        if(E.filename == NULL) {
            EditorSetStatusMessage("Save aborted");
            return;
        }
        HighlightSyntax();
    }
    int len;
    char* buf = EditorRowsToString(&len);
    int fd = open(E.filename, O_RDWR | O_CREAT, 0644);
    if(fd != -1) {
        if(ftruncate(fd, len) != -1) {
            if(write(fd, buf, len) == len) {
                close(fd);
                free(buf);
                E.dirty = 0;
                EditorSetStatusMessage("%d bytes written to disk", len);
                return;
            }
        }
        close(fd);
    }
    free(buf);
    EditorSetStatusMessage("Can't save! I/O error: %s", strerror(errno));
}

void EditorProcessKeypress() {
    static int quit_times = KILO_QUIT_TIMES;
    int c = TerminalReadKey();
    switch(c) {
        case '\r':
            EditorInsertNewline();
            break;
        case CTRL_KEY('q'):
            if(E.dirty && quit_times > 0) {
                EditorSetStatusMessage("WARNING!!! File has unsaved changes. "
                "Press Ctrl-Q %d more times to quit.", quit_times);
                quit_times--;
                return;
            }
            write(STDOUT_FILENO, "\x1b[2J", 4);
            write(STDOUT_FILENO, "\x1b[H", 3);
            exit(0);
            break;  
        case CTRL_KEY('s'):
            EditorSave();
            break;
        case CTRL_KEY('o'):
        case HOME_KEY:
            E.cx = 0;
            break;
        case END_KEY:
            if(E.cy < E.numrows) 
                E.cx = E.row[E.cy].size;
            break;
        case CTRL_KEY('f'):
            EditorFind();
            break;
        case BACKSPACE:
        case CTRL_KEY('h'):
        case DEL_KEY:
            if(c == DEL_KEY) TerminalMoveCursor(ARROW_RIGHT);
            EditorDelChar();
            break;
        case PAGE_UP:
        case PAGE_DOWN:
            {
                if(c == PAGE_UP) {
                    E.cy = E.rowoff;
                } else if(c == PAGE_DOWN) {
                    E.cy = E.rowoff + E.screenrows - 1;
                    if(E.cy >E.numrows) E.cy = E.numrows;
                }

                int times = E.screenrows;
                while(times--) {
                    TerminalMoveCursor(c == PAGE_UP ? ARROW_UP : ARROW_DOWN);
                }
                break;
            }
        case ARROW_UP:
        case ARROW_DOWN:
        case ARROW_LEFT:
        case ARROW_RIGHT:
            TerminalMoveCursor(c);
            break;
        case CTRL_KEY('l'):
        case '\x1b':
            break;
        default:
            EditorInsertChar(c);
            break;   
    }
    quit_times = KILO_QUIT_TIMES;
}



void EditorDrawRows(struct abuf *ab) {
    int y;
    for(y = 0; y < E.screenrows; y++) {
        int filerow = y + E.rowoff;
        if(filerow >= E.numrows) {
            if(E.numrows == 0 && y == E.screenrows / 3) {
                char welcome[80];
                int welcomelen = snprintf(welcome, sizeof(welcome), "Kilo editor -- version %s", KILO_VERSION);
                if(welcomelen > E.screencols) welcomelen = E.screencols;
                int padding = (E.screencols - welcomelen) / 2;
                if(padding) {
                    abAppend(ab, "~", 1);
                    padding--;
                }
                while(padding--) abAppend(ab, " ", 1);
                abAppend(ab, welcome, welcomelen); 
            } else {
                abAppend(ab, "~", 1);
            }
        } else {
            int len = E.row[filerow].rsize - E.coloff;
            if(len < 0) len = 0;
            if(len > E.screencols) len = E.screencols;
            char *c = &E.row[filerow].render[E.coloff];
            unsigned char* hl = &E.row[filerow].hl[E.coloff];
            int current_color = -1;
            int j;
            for(j = 0; j < len; j++) {
                if(iscntrl(c[j])) {
                    char sym = (c[j] <= 26) ? '@' + c[j]: '?';
                    abAppend(ab, "\x1b[7m", 4);
                    abAppend(ab, &sym, 1);
                    abAppend(ab, "\x1b[m", 3);
                    if(current_color != -1) {
                        char buf[16];
                        int clen = snprintf(buf, sizeof(buf), "\x1b[%dm", current_color);
                        abAppend(ab, buf, clen);
                    }
                } else if(hl[j] == HL_NORMAL) {
                    if(current_color != -1) {
                        abAppend(ab, "\x1b[39m", 5);
                        current_color = -1;
                    }
                    abAppend(ab, &c[j], 1);
                } else {
                    int color = HighlightSyntaxToColor(hl[j]);
                    if(color != current_color) {
                        current_color = color;
                        char buf[16];
                        int clen = snprintf(buf, sizeof(buf), "\x1b[%dm", color);
                        abAppend(ab, buf, clen);
                    }
                    abAppend(ab, &c[j], 1);
                }
            }
            abAppend(ab, "\x1b[39m", 5);
        }
        abAppend(ab, "\x1b[K", 3);
        abAppend(ab, "\r\n", 2);
    }
}

void EditorRefreshScreen() {
    TerminalScroll();

    struct  abuf ab = ABUF_INIT;

    abAppend(&ab, "\x1b[?25l", 6);
    abAppend(&ab, "\x1b[H", 3);

    EditorDrawRows(&ab);
    EditorDrawStatusBar(&ab);
    EditorDrawMessageBar(&ab);

    char buf[32];
    snprintf(buf, sizeof(buf), "\x1b[%d;%dH", (E.cy -E.rowoff) +1, (E.rx - E.coloff)+1);
    abAppend(&ab, buf, strlen(buf));
    abAppend(&ab, "\x1b[?25h", 6);

    write(STDOUT_FILENO, ab.b, ab.len);
    abFree(&ab);
}

char* EditorPrompt(char* prompt, void(*callback)(char*, int)) {
    size_t bufsize = 128;
    char* buf = malloc(bufsize);

    size_t buflen = 0;
    buf[0] = '\0';

    while(1) {
        EditorSetStatusMessage(prompt, buf);
        EditorRefreshScreen();

        int c = TerminalReadKey();

        if(c == DEL_KEY || c == CTRL_KEY('h') || c == BACKSPACE) {
            if(buflen != 0) buf[--buflen] = '\0';
        } else if(c == '\x1b') {
            EditorSetStatusMessage("");
            if(callback) callback(buf, c);
            free(buf);
            return NULL;
        } else if(c == '\r') {
            if(buflen != 0) {
                EditorSetStatusMessage("");
                if(callback) callback(buf, c);
                return buf;
            }
        } else if(!iscntrl(c) && c < 128) {
            if(buflen == bufsize-1) {
                bufsize *= 2;
                buf = realloc(buf, bufsize);
            }
            buf[buflen++] = c;
            buf[buflen] = '\0';
        }

        if(callback) callback(buf, c);
    }
}



void EditorDrawStatusBar(struct abuf *ab) {
    abAppend(ab, "\x1b[7m", 4);
    char status[80], rstatus[80];
    int len = snprintf(status, sizeof(status), "%.20s - %d lines %s", E.filename ? E.filename : "[No Name]", E.numrows, E.dirty ? "(modified)": "");
    int rlen = snprintf(rstatus, sizeof(rstatus), "%s | %d/%d", E.syntax ? E.syntax->filetype : "no ft", E.cy+1, E.numrows);
    if(len > E.screencols) len = E.screencols;
    abAppend(ab, status, len);
    while(len <E.screencols) {
        if(E.screencols - len == rlen) {
            abAppend(ab, rstatus, rlen);
            break;
        } else {
            abAppend(ab, " ", 1);
            len++;
        }
    }
    abAppend(ab, "\x1b[m", 3);
    abAppend(ab, "\r\n", 2);
}

void EditorFind() {
    int saved_cx = E.cx;
    int saved_cy = E.cy;
    int saved_coloff = E.coloff;
    int saved_rowoff = E.rowoff;

    char* query = EditorPrompt("Search: %s (Use Esc/Arrows/Enter)", EditorFindCallback);
    if(query) {
        free(query);
    } else {
        E.cx = saved_cx;
        E.cy = saved_cy;
        E.coloff = saved_coloff;
        E.rowoff = saved_rowoff;
    }
}

void EditorFindCallback(char* query, int key) {
    static int last_match = -1;
    static int direction = 1;
    static int saved_hl_line;
    static char* saved_hl = NULL;

    if(saved_hl) {
        memcpy(E.row[saved_hl_line].hl, saved_hl, E.row[saved_hl_line].rsize);
        free(saved_hl);
        saved_hl = NULL;
    }

    if(key == '\r' || key == '\x1b') {
        last_match = -1;
        direction = 1;
        return;
    } else if(key == ARROW_RIGHT || key == ARROW_DOWN) {
        direction = 1;
    } else if(key == ARROW_LEFT || key == ARROW_UP) {
        direction = -1;
    } else {
        last_match = -1;
        direction = 1;
    }
    if(last_match == -1) direction = 1;
    int current = last_match;
    int i;
    for(i = 0; i < E.numrows; i++) {
        current += direction;
        if(current == -1) current = E.numrows - 1;
        else if(current == E.numrows) current = 0;

        Row* row = &E.row[current];
        char* match = strstr(row->render, query);
        if(match) {
            last_match = current;
            E.cy = current;
            E.cx = TerminalRowRxToCx(row, match-row->render);
            E.rowoff = E.numrows;
            saved_hl_line = current;
            saved_hl = malloc(row->rsize);
            memcpy(saved_hl, row->hl, row->rsize);
            memset(&row->hl[match-row->render], HL_MATCH, strlen(query));
            break;
        }
    }
}

char* EditorRowsToString(int* buflen) {
    int totlen = 0;
    int j;
    for(j = 0; j < E.numrows; j++) 
        totlen += E.row[j].size + 1;
    *buflen = totlen;
    char* buf = malloc(totlen);
    char* p = buf;
    for(j =0; j < E.numrows; j++) {
        memcpy(p, E.row[j].chars, E.row[j].size);
        p += E.row[j].size;
        *p = '\n';
        p++;
    }
    return buf;
}


void EditorSetStatusMessage(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(E.statusmsg, sizeof(E.statusmsg), fmt, ap);
    va_end(ap);
    E.statusmsg_time = time(NULL);
}

void EditorDrawMessageBar(struct abuf *ab) {
    abAppend(ab, "\x1b[K", 3);
    int msglen = strlen(E.statusmsg);
    if(msglen > E.screencols) msglen = E.screencols;
    if(msglen && time(NULL) - E.statusmsg_time < 5) 
        abAppend(ab, E.statusmsg, msglen);
}

void EditorInsertNewline() {
    if(E.cx == 0) {
        EditorInsertRow(E.cy, "", 0);
    } else {
        Row* row = &E.row[E.cy];
        EditorInsertRow(E.cy+1, &row->chars[E.cx], row->size-E.cx);
        // 这里指针发生了变化，之前的指针被释放
        row = &E.row[E.cy]; 
        row->size = E.cx;
        row->chars[row->size] = '\0';
        RowUpdate(row);
    }
    E.cy++;
    E.cx = 0;
} 


void EditorInsertRow(int at, char* s, size_t len) {
    if(at < 0 || at > E.numrows) return;

    E.row = realloc(E.row, sizeof(Row)*(E.numrows+1));
    memmove(&E.row[at+1], &E.row[at], sizeof(Row)*(E.numrows-at));

    for(int j = at+1; j <= E.numrows; j++) E.row[j].idx++;

    E.row[at].idx = at;
    
    E.row[at].size = len;
    E.row[at].chars = malloc(len+1);
    memcpy(E.row[at].chars, s, len); 
    E.row[at].chars[len] = '\0';
    E.row[at].rsize = 0;
    E.row[at].render = NULL;
    E.row[at].hl = NULL;
    E.row[at].hl_open_comment = 0;
    RowUpdate(&E.row[at]);
    E.numrows ++;
    E.dirty++;

}

void EditorDelRow(int at) {
    if(at < 0 || at >= E.numrows) return;
    RowFree(&E.row[at]);
    memmove(&E.row[at], &E.row[at+1], sizeof(Row)*(E.numrows-at-1));
    for(int j=at; j < E.numrows-1; j++) E.row[j].idx--;
    E.numrows --;
    E.dirty++;
}

void EditorInsertChar(int c) {
    if(E.cy == E.numrows) {
        EditorInsertRow(E.numrows, "", 0);
    }
    RowInsertChar(&E.row[E.cy], E.cx, c);
    E.cx++;
}

void EditorDelChar() {
    if(E.cy == E.numrows) return ;
    if(E.cx == 0 && E.cy == 0) return;
    Row* row = &E.row[E.cy];
    if(E.cx > 0) {
        RowDelChar(row, E.cx-1);
        E.cx--;
    } else {
        E.cx = E.row[E.cy-1].size;
        RowAppendString(&E.row[E.cy-1], row->chars, row->size);
        EditorDelRow(E.cy);
        E.cy--; 
    }
}


void abAppend(struct abuf *ab, const char * s, int len) {
    char *new = realloc(ab->b, ab->len + len);
    if(new == NULL) return;
    memcpy(&new[ab->len], s, len);
    ab->b = new;
    ab->len += len;
}

void abFree(struct abuf *ab) {
    free(ab->b);
}