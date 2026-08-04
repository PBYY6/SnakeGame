#ifndef GAME_H
#define GAME_H
#include"food.h"

typedef struct {

    // 吃了多少个普通食物
    int foodCount;


    // 还需要吃几个普通食物出现大得分点
    int needFood;


    // 大得分点剩余时间
    int bigFoodTime;


    // 大得分点当前分值
    int bigScore;

    //是否存在大得分点
    int bigFood;

    //帧计数，用来控制时间
    int timeCount;


} Game;



void initGame(Game *game);

void createBigFood(Game *game, Food *food);

void eatNormalFood(Game *game, Food *food);

void eatBigFood (Game *game, Food *food);

void updateBigFood (Game *game, Food *food);
#endif