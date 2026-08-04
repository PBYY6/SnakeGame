#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"food.h"

void createFood (Food *food) {

    food->x = rand () % 28 + 1;
    food->y = rand () % 18 + 1;

    food->type = 0;
    
}