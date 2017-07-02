/* drawBall.c */
#include "runner.h"
#include <math.h>

void initBall(struct Ball * b){
  b->ID = BALL;
  b->x = SCREEN_WIDTH / HALF;
  b->y = SCREEN_HEIGHT * 0.25;
  b->speed = 0;
  b->alive = 0;
  b->color = 255;
  b->angle = 0;
  
}

void moveBall(struct Ball * b){

  b->y += (double)b->speed * sin(b->angle);
  b->x += (double)b->speed * cos(b->angle);
}

void drawBall(struct Ball * b){
  
  al_draw_filled_circle(b->x, b->y, 2, al_map_rgb(0,b->color,0));

}
