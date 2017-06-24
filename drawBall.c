/* drawBall.c */
#include "runner.h"
#include <math.h>

void initBall(struct Ball * b){
  b->ID = BALL;
  b->x = SCREEN_WIDTH / HALF;
  b->y = SCREEN_HEIGHT / HALF;
  b->speed = 0;
  b->alive = 0;
  b->color = 255;
  b->angle = 0;
  
}

void moveBall(struct Ball * b){

  b->y += b->speed * sin(b->angle);
  b->x += b->speed * cos(b->angle);
  if(b->y > SCREEN_HEIGHT || b->y < 0
      || b->x < 0 || b->x > SCREEN_WIDTH){

    b->alive = 0;
  }
}
void drawBall(struct Ball * b){
  if(b->y > 550 && b->y < 650){
 // fprintf(stderr, "drew at %d\n", b->y);
  }
  al_draw_filled_circle(b->x, b->y, 2, al_map_rgb(0,b->color,0));

}
