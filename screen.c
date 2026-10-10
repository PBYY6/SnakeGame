#include<windows.h>
#include"screen.h"

void clearScreen () {
    COORD pos ;
    
    pos.X = 0;
    pos.Y = 0;

    SetConsoleCursorPosition (
        GetStdHandle (STD_OUTPUT_HANDLE),
        pos
    );
}