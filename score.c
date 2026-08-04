#include "score.h"


void initScore(Score *score)
{
    score->score = 0;
}


void addScore(Score *score)
{
    score->score += 10;
}