#ifndef TERMINAL_H
#define TERMINAL_H

#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/types.h>

#include "common.h"
#include "row.h"

#define CTRL_KEY(k) ((k) & 0x1f)

enum KeyType {
    BACKSPACE = 127,
    ARROW_LEFT = 1000,
    ARROW_RIGHT,
    ARROW_UP,
    ARROW_DOWN,
    DEL_KEY,
    HOME_KEY,
    END_KEY,
    PAGE_UP,
    PAGE_DOWN
};

void TerminalMoveCursor(int key);
int TerminalRowRxToCx(Row* row, int rx);
int TerminalRowCxToRx(Row* row, int cx);
void TerminalScroll();

void TerminalDisableRawMode();
void TerminalEnableRawMode();
int TerminalReadKey();
int TerminalGetCursorPosition(int *rows, int *cols);
int TerminalGetWindowSize(int *rows, int *cols);

#endif