#include<stdio.h>
#include<windows.h>
#include"map.h"
#include"snake.h"
#include<stdlib.h>
#include"input.h"
#include"food.h"
#include"score.h"
#include"game.h"
#include"screen.h"


int main () {
    printf ("Snake Game Start !\n");
    Sleep (1000);
    clearScreen ();

    Snake snake;
    Food food;
    Score score;
    Game game;


    initSnake (&snake);

    createFood (&food);

    initScore (&score);

    initGame (&game);

    while (1) {
        
        input (&snake);

        
       if (!snake.pause) moveSnake (&snake);
        wrapSnake(&snake);

        updateBigFood (&game, &food);
        /*if (eatFood (&snake, &food) ) {

            growSnake(&snake);

             addScore(&score);

            createFood (&food);

        } */
       if(eatFood(&snake,&food)) {

            growSnake(&snake);

            if(food.type == 0)
              {
              eatNormalFood(&game, &food);

              addScore (&score);

              if (food.type == 0) {

                createFood (&food);
                }
              }   else {

                score.score += game.bigScore;

                eatBigFood (&game, &food);

                createFood (&food);

            }

            
       }

        
        if ( checkCrash(&snake)) {

            printf ("Game Over !\n");
            break;
        }

        //system ("cls");
        clearScreen ();

        printMap (&snake, &food);

        printf("Score: %d\n", score.score);

        if (snake.pause) {
            printf ("Game Pause\n");
        }

        Sleep (125);



    }
   
    
    return 0;
}