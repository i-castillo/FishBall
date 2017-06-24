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

  }

}

int hitBall(struct Player * p, struct Ball * b){ 

  
  return 0;
}

void resetPlayer(struct Player * p){
  p->y = SCREEN_HEIGHT * 0.75 + 50;

};
