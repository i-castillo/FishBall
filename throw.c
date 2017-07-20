/* baseball.c */
#include <math.h>
#include "runner.h"

/* Throws the ball */
void throwBall(struct Ball * b, int speed){

  b->x = SCREEN_WIDTH / 2;
  b->y = SCREEN_HEIGHT / 4;
  b->alive = 1; //ball can be hit
  b->speed = speed;
  b->angle = acos(0);
  b->hit = 0;

}

/* Catches the ball */
int catchBall(struct Catcher c[], int numCatchers, struct Ball * b, int radius){

  if(b->y >= SCREEN_HEIGHT || b->y <= 0
      || b->x <= 0 || b->x >= SCREEN_WIDTH){

    return 2;
  } 
  if(b->speed == 0){
    return 1;
  }

  int i;
  for(i = 0; i < numCatchers; i++){

    if( collide(c[i].x, c[i].y, b->x, b->y, radius)){
      b->speed = 0;
      return 1;
    } 

  }

  return 0;
}

/* Hits the ball */
int hitBall(struct Player * p, struct Ball * b){ 


  if(b->y >= SCREEN_HEIGHT || b->y <= 0
      || b->x <= 0 || b->x >= SCREEN_WIDTH){

    return -1;
  } 

  if(b->y + 6 >= p->y && b->alive == 1 && b->hit == 0
      && p->x + 15 >= b->x){
    p->y = b->y;

    b->hit = 1;

    double dx =  PIVOT_X - p->x;
    double dy = PIVOT_Y - p->y;
    double angle =  atan2(dy, dx) + acos(0);

    b->angle = angle;
    b->speed = 0;

    b->speed = 1 * sqrt(fabs(p->speed) * fabs(p->power));
    if(b->speed == 0){
      b->alive = 0;

    }
    p->speed = 0;
    if(b->angle < 0 && b->angle > -0.959){
      return -2;
    }

    p->score += fabs(b->speed) + 10;    
    int returnval = fabs(p->power);

    if(returnval > 6){
      return 4;
    }
    else if(returnval > 4){
      return 3;
    }
    else if(returnval > 3){
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

void checkScore(struct Runner r[], int numRunners, int * score){
  int i;
  for(i = 0; i < numRunners; i++){
    if(r[i].scored){
      *score += 20;
      r[i].scored = 0;
    }
  }
}


