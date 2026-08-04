#include "game.h"
#include<stdlib.h>
#include<stdio.h>

void initGame(Game *game)
{
    game->foodCount = 0;


    // 默认吃5个普通食物出现大点
    game->needFood = 5;


    // 一开始没有大得分点
    game->bigFoodTime = 0;


    game->bigScore = 0;


    game->bigFood = 0;

    game->timeCount = 0;

}

/*void eatNormalFood(Game *game)
{
    game->foodCount++;


    if(game->foodCount >= game->needFood)
    {
        createBigFood(game);
    }
}



/*void createBigFood(Game *game)
{
    game->bigFood = 1;

    game->bigFoodTime = 5;

    game->bigScore = 30;

    game->foodCount = 0;
}*/

void eatNormalFood(Game *game, Food *food)
{
    game->foodCount++;

    if(game->foodCount >= game->needFood)
    {
        createBigFood(game, food);
    }
}

void createBigFood(Game *game, Food *food)
{
    game->bigFood = 1;

    game->bigFoodTime = 5;

    game->bigScore = 30;

    game->foodCount = 0;


    food->x = rand()%28+1;
    food->y = rand()%18+1;

    food->type = 1;
}

void eatBigFood (Game *game, Food *food) {

    game->bigFood = 0;

    game->bigFoodTime = 0;

    food->type = 0;
}

void updateBigFood (Game *game, Food *food) {

    if (game->bigFood == 0) {

        return ;

    }

    game->timeCount++;

    if (game->timeCount >= 8 ) {

        game->timeCount = 0;

        game->bigFoodTime--;

        game->bigScore -= 5;

        printf (
            "大得分点剩余时间：%d   当前价值：%d\n",
            game->bigFoodTime,
            game->bigScore
        );

        if (game->bigFoodTime <= 0) {

            game->bigFood = 0;

            food->type = 0;

            game->bigScore = 0;

            createFood (food);
        }
    }
}