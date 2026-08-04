#include<stdio.h>
#include"map.h"

#define HEIGHT 20
#define WIDTH 30


   void printMap (Snake *snake, Food *food) {

     char map[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; i++) {

        for (int j = 0; j < WIDTH; j++) {

            if (i == 0 || i == HEIGHT - 1 
            || j == 0 || j == WIDTH - 1 ) {

                map[i][j] = '#';
            }
            else {
                map[i][j] = ' ';
            }
        } 
    }


   // map[food->y][food->x] = '*';

   if (food->type == 0) {

    map[food->y][food->x] = '*';

   }else {

    map[food->y][food->x] = '0';

   }


    
   for (int i = 0; i < snake->length; i++) {

    if (i == 0) {
        map[snake->y[i]][snake->x[i]] = '@';
    }
    else {
        map[snake->y[i]][snake->x[i]] = 'o';
    }
   }

    for (int i = 0; i < HEIGHT; i++) {

        for (int j = 0; j < WIDTH; j++) {

            printf ("%c", map[i][j]);
        }
        printf ("\n");
    }
   }
   