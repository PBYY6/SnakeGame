#include<stdio.h>
#include<windows.h>
#include"input.h"

void input (Snake *snake) {

    if (GetAsyncKeyState ( 'W' ) ) {

       if (snake->dir != 3) {
        snake->dir = 2;
       }

    }
    else if (GetAsyncKeyState ( 'S' )) {

       if (snake->dir != 2) {
        snake->dir = 3;
       }

    }
    else if (GetAsyncKeyState ( 'A' )) {

        if (snake->dir != 0) {
        snake->dir = 1;
       }

    }
    else if (GetAsyncKeyState ( 'D')) {

        if (snake->dir != 1) {
        snake->dir = 0;
       }

    }
    else if (GetAsyncKeyState ( 'P')) {
        snake->pause = !snake->pause;
    }
}