/* drawPlayer.c. */
#include "runner.h"

void initPlayer(struct Player * p){
  p->ID = PLAYER;
  p->x = SCREEN_WIDTH / HALF;
  p->y = SCREEN_HEIGHT * 0.75;
  p->health = HEALTH;
  p->boundY = BOUND;
  p->boundX = BOUND;
  p->alive = 0;

}

void drawPlayer(struct Player * p){
  al_draw_line(0.25 * SCREEN_WIDTH , 0.75 * SCREEN_HEIGHT, p->x + 25,
      p->y + 10, al_map_rgb(255, 0, 0), 2);

}
