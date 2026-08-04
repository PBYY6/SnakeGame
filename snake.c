#include<stdio.h>
#include"snake.h"


 void initSnake (Snake *snake) {
   snake->length = 3;

   snake->x[0] = 5;
   snake->y[0] = 5;

   snake->x[1] = 4;
   snake->y[1] = 5;

   snake->x[2] = 3;
   snake->y[2] = 5;

    snake->dir = 0;

    snake->pause = 0;
 }

 

 void moveSnake (Snake *snake) {
 
   for (int i = snake->length - 1; i > 0; i--) {
      
      snake->x[i] = snake->x[i-1];
      snake->y[i] = snake->y[i-1];

   }
   switch (snake->dir) {
      case 0:
      snake->x[0]++;
      break;

      case 1:
      snake->x[0]--;
      break;

      case 2:
      snake->y[0]--;
      break;

      case 3:
      snake->y[0]++;
      break;
   }
 }

void wrapSnake(Snake *snake)
{
    if(snake->x[0] >= 29)
    {
        snake->x[0] = 1;
    }

    if(snake->x[0] <= 0)
    {
        snake->x[0] = 28;
    }


    if(snake->y[0] >= 19)
    {
        snake->y[0] = 1;
    }

    if(snake->y[0] <= 0)
    {
        snake->y[0] = 18;
    }
}


int checkCrash(Snake *snake)
{
    
    for(int i = 1; i < snake->length; i++)
    {
        if(snake->x[0] == snake->x[i] &&
           snake->y[0] == snake->y[i])
        {
            return 1;
        }
    }


    return 0;
    
}

 int eatFood (Snake *snake, Food *food) {
   if (snake->x[0] == food->x &&
   snake->y[0] == food->y) {
      return 1;
   }

   return 0;
 }

 void growSnake(Snake *snake)
{
    if(snake->length < MAX_LENGTH)
    {
        snake->x[snake->length] = 
        snake->x[snake->length - 1];

        snake->y[snake->length] = 
        snake->y[snake->length - 1];

        snake->length++;
    }
}