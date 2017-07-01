/* throw.c */
#include <math.h>
#include "runner.h"

void throwBall(struct Ball * b){
  if(b->alive == 0){

    b->x = SCREEN_WIDTH / HALF;
    b->y = SCREEN_HEIGHT * 0.25;
    b->alive = 1; //ball can be hit
    b->speed = 3;
    b->angle = acos(0);
    b->hit = 0;

  }

}

int hitBall(struct Player * p, struct Ball * b){ 

  if(b->y + 6 >= p->y && b->alive == 1 && b->hit == 0
      && p->x + 15 >= b->x){

    b->hit = 1;
    double d = INIT_PLAYER_Y - p->y;
    p->y = b->y;


    double angle = atan(d / OFFSET_LENGTH);
    b->angle = angle;
    b->speed = 0;
    b->speed = -1 * sqrt(fabs(p->speed) * fabs(p->power));
    if(b->speed == 0){
      b->alive = 0;

    }
    p->speed = 0;

    p->score += fabs(b->speed);
    fprintf(stderr, "%d\n", p->score); 
    int returnval = fabs(p->power);

    if(returnval > 25){
      return 4;
    }
    else if(returnval > 16){
      return 3;
    }
    else if(returnval > 4){
      return 2;
    }
    else if(returnval > 1){
      return 1;
    }
    else{
      return 1;
    }
  }
  return 0;
  }

  void resetPlayer(struct Player * p){
    p->y = INIT_PLAYER_Y;
    p->speed = 0;
    p->power = 0;

  };
