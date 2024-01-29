#ifndef ROW_H
#define ROW_H

#include "common.h"

typedef struct Row {
    int idx;
    int size;
    int rsize;
    char* chars;
    char* render;
    unsigned char *hl;
    int hl_open_comment;
} Row;

void RowFree(Row* row);
void RowUpdate(Row* row);

void RowInsertChar(Row* row, int at, int c);
void RowDelChar(Row* row, int at);
void RowAppendString(Row* row, char* s, size_t len);

void RowUpdateSyntax(Row* row);



#endif