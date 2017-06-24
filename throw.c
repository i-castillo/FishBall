#include "runner.h"
void throwBall(struct Ball * b){

  b->x = SCREEN_WIDTH / HALF;
  b->y = SCREEN_HEIGHT/ HALF;

  b->speed = 3; 



}

void moveBall(struct Ball * b){

  b->y += b->speed;

}
