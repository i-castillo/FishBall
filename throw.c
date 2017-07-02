/* throw.c */
#include <math.h>
#include "runner.h"

void throwBall(struct Ball * b){

    b->x = SCREEN_WIDTH / HALF;
    b->y = SCREEN_HEIGHT * 0.25;
    b->alive = 1; //ball can be hit
    b->speed = 3;
    b->angle = acos(0);
    b->hit = 0;

  

}

int catchBall(struct Catcher c[4], struct Ball * b){

  if(b->y >= SCREEN_HEIGHT || b->y <= 0
      || b->x <= 0 || b->x >= SCREEN_WIDTH){
    
    return 2;
  } 
  if(b->speed == 0){
    return 1;
  }

  int i;
  for(i = 0; i < 4; i++){
    
    if( fabs(b->x - c[i].x) < 20 && fabs(b->y - c[i].y) < 20){
      b->speed = 0;
      return 1;
    } 

  }

  return 0;
}

int hitBall(struct Player * p, struct Ball * b){ 

  if(b->y + 6 >= p->y && b->alive == 1 && b->hit == 0
      && p->x + 15 >= b->x){
    p->y = b->y;

    b->hit = 1;

    double dx =  PIVOT_X - p->x;
    double dy = PIVOT_Y - p->y;
    double angle =  atan2(dy, dx) + acos(0);
    fprintf(stderr, "\n%f %f\n", angle, angle * 180/ 3.14159);

    b->angle = angle;
    b->speed = 0;
    b->speed = 1 * sqrt(fabs(p->speed) * fabs(p->power));
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
      return 0;
    }
  }
  return 0;
}

void resetPlayer(struct Player * p){
  p->y = INIT_PLAYER_Y;
  p->speed = 0;
  p->power = 0;

};
