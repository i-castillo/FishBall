/* throw.c */
#include <math.h>
#include "runner.h"

void throwBall(struct Ball * b){
  if(b->alive == 0){

    b->x = SCREEN_WIDTH / HALF;
    b->y = SCREEN_HEIGHT/ HALF;
    b->alive = 1; //ball can be hit
    b->speed = 3;
    b->angle = acos(0);
    b->hit = 0;

  }

}

int hitBall(struct Player * p, struct Ball * b){ 

  if(b->y > p->y && b->alive == 1 && b->hit == 0){
    b->hit = 1;
    int d = p->y - INIT_PLAYER_Y;

    double angle = atan2(d, OFFSET_LENGTH) + acos(0);
    b->angle = angle;
    b->speed = -1 * fabs(1 * (p->speed * 3 + 1));
    (p->score) += p->speed;


    return 1;
  }
  return 0;
}

void resetPlayer(struct Player * p){
  p->y = SCREEN_HEIGHT * 0.75 + 50;

};
