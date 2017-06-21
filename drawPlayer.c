/* drawPlayer.c. */
#include "runner.h"

void initPlayer(struct Player * p){
  p->ID = PLAYER;
  p->x = SCREEN_WIDTH / HALF;
  p->health = HEALTH;
  p->boundY = BOUND;
  p->boundX = BOUND;

}

void drawPlayer(struct Player * p){
  al_draw_filled_rectangle(p->x, 20, p->x + 10, 30, al_map_rgb(255, 0, 0));


}
