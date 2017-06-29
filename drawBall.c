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

int moveBall(struct Ball * b){

  b->y += (double)b->speed * sin(b->angle);
  b->x += (double)b->speed * cos(b->angle);
//  fprintf(stderr, "%d %d \n", b->x, b->y);
  if(b->y >= SCREEN_HEIGHT || b->y <= 0
      || b->x <= 0 || b->x >= SCREEN_WIDTH){
    b->alive = 0;
    return 1;
  } 
  return 0;
}
void drawBall(struct Ball * b){
  if(b->y > 550 && b->y < 650){
 // fprintf(stderr, "drew at %f\n", b->y);
  }
  al_draw_filled_circle(b->x, b->y, 2, al_map_rgb(0,b->color,0));

}
