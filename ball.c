/* ball.c */
/* Includes subroutines to initialize a ball, move a ball, 
   and draw a ball. */
#include "runner.h"
#include <math.h>

/* Initializes the ball. */
void initBall(struct Ball * b){
  
  b->x = SCREEN_WIDTH / 2; 
  b->y = SCREEN_HEIGHT / 4;
  b->speed = 0;
  b->alive = 0;
  b->angle = 0;
  b->image = al_load_bitmap(BALL_IMAGE);
  b->bmWidth = al_get_bitmap_width(b->image) /2;
  b->bmHeight = al_get_bitmap_height(b->image) /2;
}

/* Moves the ball. */
void moveBall(struct Ball * b){

  b->y += (double)b->speed * sin(b->angle);
  b->x += (double)b->speed * cos(b->angle);
}

/* Draws the ball. */
void drawBall(struct Ball * b){
  
  al_draw_bitmap(b->image, b->x - b->bmWidth, b->y - b->bmHeight, 0);

  /* Primitive image. */
  //al_draw_filled_circle(b->x, b->y, 2, al_map_rgb(255,b->color,255));

}

/* Destorys allocated memory associated with ball */
void destoryBall(struct Ball * b){
  al_destroy_bitmap(b->image);
}
