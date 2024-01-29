#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "row.h"
#include "editor.h"

void RowFree(Row* row) {
    free(row->render);
    free(row->chars);
    free(row->hl);
}

void RowUpdate(Row* row) {
    int tabs = 0;
    int j;

    for(j = 0; j < row->size; j++) 
        if(row->chars[j] == '\t') tabs++;
    free(row->render);

    row->render = malloc(row->size + tabs*(KILO_TAB_STOP-1) + 1);
    int idx = 0;
    for(j = 0; j < row->size; j++) {
        if(row->chars[j] == '\t') {
            row->render[idx++] = ' ';
            while(idx % KILO_TAB_STOP != 0) row->render[idx++] = ' ';
        } else {
            row->render[idx++] = row->chars[j];
        }
    }
    row->render[idx] = '\0';
    row->rsize = idx;

    RowUpdateSyntax(row);
}


void RowInsertChar(Row* row, int at, int c) {
    if(at < 0 || at > row->size) at = row->size;
    row->chars = realloc(row->chars, row->size+2);
    memmove(&row->chars[at+1], &row->chars[at], row->size-at+1);
    row->size++;
    row->chars[at] = c;
    RowUpdate(row);
    E.dirty++;
} 

void RowDelChar(Row* row, int at) {
    if(at < 0 || at >= row->size) return ;
    memmove(&row->chars[at], &row->chars[at+1], row->size-at);
    row->size--;
    RowUpdate(row);
    E.dirty++;
}

void RowAppendString(Row* row, char* s, size_t len) {
    row->chars = realloc(row->chars, row->size + len + 1);
    memcpy(&row->chars[row->size], s, len);
    row->size += len;
    row->chars[row->size] = '\0';
    RowUpdate(row);
    E.dirty++;
}

void RowUpdateSyntax(Row* row) {
    row->hl = realloc(row->hl, row->rsize);
    memset(row->hl, HL_NORMAL, row->rsize);
    if(E.syntax == NULL) return;

    char** keywords = E.syntax->keywords;

    char* scs = E.syntax->singleline_comment_start;
    char* mcs = E.syntax->multiline_comment_start;
    char* mce = E.syntax->multiline_comment_end;
    int scs_len = scs ? strlen(scs) : 0;
    int mcs_len = mcs? strlen(mcs) : 0;
    int mce_len = mce? strlen(mce) : 0;

    int prev_sep = 1;
    int in_string = 0;
    int in_comment = row->idx > 0 && E.row[row->idx-1].hl_open_comment;

    int i = 0;
    while(i < row->rsize) {
        char c = row->render[i];
        unsigned char prev_hl = (i > 0) ? row->hl[i-1]: HL_NORMAL;

        if(scs_len && !in_string && !in_comment) {
            if(!strncmp(&row->render[i], scs, scs_len)) {
                memset(&row->hl[i], HL_COMMENT, row->rsize-i);
                break;
            }
        }

        if(mcs_len && mce_len && !in_string) {
            if(in_comment) {
                row->hl[i] = HL_MLCOMMENT;
                if(!strncmp(&row->render[i], mce, mce_len)) {
                    memset(&row->hl[i], HL_MLCOMMENT, mce_len);
                    i += mce_len;
                    in_comment = 0;
                    prev_sep = 1;
                    continue;
                }  else {
                    i++;
                    continue;
                }
            } else if(!strncmp(&row->render[i], mcs, mcs_len)) {
                memset(&row->hl[i], HL_MLCOMMENT, mcs_len);
                i += mcs_len;
                in_comment = 1;
                continue;
            }
        }

        if(E.syntax->flags & HL_HIGHLIGHT_STRINGS) {
            if(in_string) {
                row->hl[i] = HL_STRING;
                if(c == '\\' && i+1 < row->rsize) {
                    row->hl[i+1] = HL_STRING;
                    i += 2;
                    continue;
                }
                if(c == in_string) in_string = 0;
                i++;
                prev_sep = 1;
                continue;
            } else {
                if(c == '"' || c == '\'') {
                    in_string = c;
                    row->hl[i] = HL_STRING;
                    i++;
                    continue;
                }
            }
        }

        if(E.syntax->flags & HL_HIGHLIGHT_NUMBERS) {
            if((isdigit(c) && (prev_sep || prev_hl == HL_NUMBER)) ||(c == '.' && prev_hl == HL_NUMBER)) {
                row->hl[i] = HL_NUMBER;
                i++;
                prev_sep = 0;
                continue;
            }
        }

        if(prev_sep) {
            int j;
            for(j = 0; keywords[j]; j++) {
                int klen = strlen(keywords[j]);
                int kw2 = keywords[j][klen-1] == '|';
                if(kw2) klen--;

                if(!strncmp(&row->render[i], keywords[j], klen) && is_separator(row->render[i+klen])) {
                    memset(&row->hl[i], kw2 ? HL_KEYWORD2 : HL_KEYWORD1, klen);
                    i += klen;
                    break;
                }
            }
            if(keywords[j] != NULL) {
                prev_sep = 0;
                continue;
            }
        }

        prev_sep = is_separator(c);
        i++;
    }
    int changed = (row->hl_open_comment != in_comment);
    row->hl_open_comment = in_comment;
    if(changed && row->idx+1 < E.numrows)
        RowUpdateSyntax(&E.row[row->idx+1]);
}