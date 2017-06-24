/* throw.c */
#include "runner.h"
void throwBall(struct Ball * b, struct Player * p){
  if(b->alive == 0){
    
  b->x = SCREEN_WIDTH / HALF;
  b->y = SCREEN_HEIGHT/ HALF;
  b->alive = 1;
  b->speed = 3; 
  

  }

  

}

void moveBall(struct Ball * b, struct Player * p){

  b->y += b->speed;
  if(b->y > SCREEN_HEIGHT || b->y < 0){
    //printf("%d %d", b->y, SCREEN_HEIGHT);
    resetPlayer(p);
    b->alive = 0;
  };
}

int hitBall(struct Player * p, struct Ball * b){  
  if(p->alive == 0 && b->alive == 1){

    p->y -= 15;
    
    b->speed = -5;

  };

  return 1;

};

void resetPlayer(struct Player * p){
  p->y = SCREEN_HEIGHT * 0.75;
  
 };
