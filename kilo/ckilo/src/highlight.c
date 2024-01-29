#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#include "common.h"
#include "highlight.h"
#include "row.h"
#include "editor.h"

char* C_HL_extensions[] = {".c", ".h", ".cpp", NULL};
char* C_HL_keywords[] = {
    "switch", "if", "while", "for", "break", "continue", "return", "else",
    "struct", "union", "typedef", "static", "enum", "class", "case", 
    "int|", "long|", "double|", "float|", "char|", "unsigned|", "signed|",
    "void|", NULL
};

struct Syntax HLDB[] = {
    {
        "c",
        C_HL_extensions,
        C_HL_keywords,
        "//", "/*", "*/",
        HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS
    },
};


int is_separator(int c) {
    return isspace(c) || c == '\0' || strchr(",.()+-/*=~%<>[];", c) != NULL;
}

int HighlightSyntaxToColor(int hl) {
    switch(hl) {
        case HL_COMMENT: 
        case HL_MLCOMMENT: return 36;
        case HL_KEYWORD1: return 33;
        case HL_KEYWORD2: return 32;
        case HL_STRING: return 35;
        case HL_NUMBER: return 31;
        case HL_MATCH: return 34;
        default: return 37;
    }
}


void HighlightSyntax() {
    E.syntax = NULL;
    if(E.filename == NULL) return ;
    char *ext = strchr(E.filename, '.');
    unsigned int HLDB_ENTRIES = sizeof(HLDB) / sizeof(HLDB[0]);
    for(unsigned int j = 0; j < HLDB_ENTRIES; j++) {
        struct Syntax* s = &HLDB[j];
        unsigned int i = 0;
        while(s->filematch[i]) {
            int is_ext = (s->filematch[i][0] == '.');
            if((is_ext && ext && !strcmp(ext, s->filematch[i])) ||
               (!is_ext && strstr(E.filename, s->filematch[i]))) {
                E.syntax = s;
                int filerow;
                for(filerow = 0; filerow < E.numrows; filerow++) {
                    RowUpdateSyntax(&E.row[filerow]);
                }
                return;
            }
            i++;
        } 
    }
}