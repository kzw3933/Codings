#ifndef EDITOR_H 
#define EDITOR_H

#include <time.h>
#include <termios.h>
#include <stdio.h>
#include <fcntl.h>
#include <error.h>
#include <stddef.h>
#include <unistd.h>

#include "common.h"
#include "highlight.h"
#include "row.h"

#define ABUF_INIT {NULL, 0}

struct Editor {
    int cx, cy;
    int rx;
    int rowoff;
    int coloff;
    int screenrows;
    int screencols;
    int numrows;
    Row* row;
    int dirty;
    char *filename;
    char statusmsg[80];
    time_t statusmsg_time;
    struct Syntax *syntax;
    struct termios orig_termios;
};

struct abuf {
    char *b;
    int len;
};

extern struct Editor E;

void die(const char *s);

void abAppend(struct abuf *ab, const char * s, int len);
void abFree(struct abuf *ab);

void EditorInit();

void EditorOpen(char *filename);
void EditorSave();

void EditorProcessKeypress();
void EditorFind();
void EditorFindCallback(char* query, int key);

void EditorInsertChar(int c);
void EditorDelChar();
void EditorInsertNewline();
void EditorInsertRow(int at, char* s, size_t len);
void EditorDelRow(int at);

char* EditorRowsToString(int* buflen);

void EditorDrawRows(struct abuf *ab);
void EditorDrawStatusBar(struct abuf *ab);
void EditorDrawMessageBar(struct abuf *ab);

void EditorRefreshScreen();
void EditorSetStatusMessage(const char* fmt, ...);
char* EditorPrompt(char* prompt, void (*callback)(char*, int));


#endif