#ifndef SNAKE_H
#define SNAKE_H

#include "food.h"

#define MAX_LENGTH 100

typedef struct {
    int x[MAX_LENGTH];
    int y[MAX_LENGTH];

    int length;

    int dir;

    int pause;
    
} Snake;


void initSnake (Snake *snake);

void moveSnake (Snake *snake);

int checkCrash (Snake *snake);

void wrapSnake(Snake *snake);

int eatFood (Snake *snake, Food *food);

void growSnake (Snake *snake);

#endif