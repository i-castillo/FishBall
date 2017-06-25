/* drawPlayer.c. */
#include "runner.h"
#include <math.h>
void initPlayer(struct Player * p){
  p->ID = PLAYER;
  p->x = INIT_PLAYER_X;
  p->y = INIT_PLAYER_Y;
  p->alive = 0;
  p->length = PLAYER_LENGTH;
  p->speed = 0;
  p->score = 0;
  calculateBound(p);

}

void movePlayer(struct Player * p){
  p->y += p->speed;
  if(p->y < INIT_PLAYER_Y - p->boundY){
    p->speed = 0;
    p->y = p->boundY + INIT_PLAYER_Y;
  };

}

void setSpeed(struct Player * p, int speed){
  if(speed == 0){
    speed = 1;
  }

  p->speed = -1 * speed;

}

void calculateBound(struct Player * p){

  p->boundY = sqrt((0.10 * SCREEN_WIDTH) * SCREEN_WIDTH /4 + 
      0.05 * SCREEN_WIDTH * 0.05 * SCREEN_WIDTH);


}

void drawPlayer(struct Player * p){
  al_draw_line(0.25 * SCREEN_WIDTH , 0.75 * SCREEN_HEIGHT, 0.25 * SCREEN_WIDTH + p->length,
      p->y + 0, al_map_rgb(255, 0, 0), 2);
  //  fprintf(stderr, "hmmmsadf %d\n", p->y);
  al_draw_rectangle(p->x- 5, p->y, p->x + 5, p->y - p->boundY, al_map_rgb(127,127,0), 1);


}
