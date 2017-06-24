/* drawBall.c */
#include "runner.h"

void initBall(struct Ball * b){
  b->ID = BALL;
  b->x = SCREEN_WIDTH / HALF;
  b->y = SCREEN_HEIGHT / HALF;
  b->speed = 0;

};

void drawBall(struct Ball * b){
  al_draw_filled_circle(b->x, b->y, 2, al_map_rgb(0,255,0));

}
