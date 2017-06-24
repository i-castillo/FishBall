/* throw.c */
#include "runner.h"
#include <math.h>
void throwBall(struct Ball * b, struct Player * p){
  if(b->alive == 0){

    b->x = SCREEN_WIDTH / HALF;
    b->y = SCREEN_HEIGHT/ HALF;
    b->alive = 1;
    b->speed = 3;
    b->angle = acos(0);


  }



}

void moveBall(struct Ball * b, struct Player * p){
  //    fprintf(stderr, "%d\n", b->y);

  b->y += b->speed * sin(b->angle);
  b->x += b->speed * cos(b->angle);
  if(b->y > SCREEN_HEIGHT || b->y < 0){

    resetPlayer(p);
    b->alive = 0;
  };
}

int hitBall(struct Player * p, struct Ball * b){  
  if(p->alive == 0 && b->alive == 1){
    b->color = 100;
    int dist = p->y - b->y + 6;
    fprintf(stderr, "p->boundy, %d b->y: %d dist: %d\n", p->boundY, b->y, dist);

    if(dist < p->boundY && dist > 0){
       p->y = b->y;

      
      b->angle = ( 90 - atan2(0.5 * dist, SCREEN_WIDTH / 4))/2;
      b->speed = -5;
      if(dist < 50){
      b->speed = -10;
      }
      else if(dist < 30){
      b->speed = -15;

      }
      else if(dist < 10){
      fprintf(stderr, "WOAW\n");
      b->speed = -30;
      }

      


      return 1;
    }
    p->y =  -p->boundY +p->y;
    
  return 0;

  }

  return 0;

};

void resetPlayer(struct Player * p){
  p->y = SCREEN_HEIGHT * 0.75 + 50;

};
