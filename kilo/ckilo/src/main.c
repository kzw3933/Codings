#include "common.h"
#include "editor.h"
#include "highlight.h"
#include "row.h"
#include "terminal.h"


int main(int argc, char *argv[]) {
    TerminalEnableRawMode();
    EditorInit();
    if(argc >= 2) {
        EditorOpen(argv[1]);
    }

    EditorSetStatusMessage("HELP: Ctrl-S = save | Ctrl-Q = quit | Ctrl-F = find");
    
    while(1) {
        EditorRefreshScreen();
        EditorProcessKeypress();
    }

    return 0;
}