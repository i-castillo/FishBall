/* drawPlayer.c. */
#include "runner.h"
#include <math.h>
void initPlayer(struct Player * p){
  p->ID = PLAYER;
  p->boundY = calculateBound(p);  
  p->x = SCREEN_WIDTH / HALF;
  p->y = SCREEN_HEIGHT * 0.75 + p->boundY;
  p->health = HEALTH;
  p->alive = 0;
  p->length = SCREEN_WIDTH / 4 + 0.05 * SCREEN_WIDTH;
  fprintf(stderr, "p->y: %d\n", p->y);

}

int calculateBound(struct Player * p){
 p->boundY = sqrt(50 * SCREEN_WIDTH /4 + 25 * 25);
 // fprintf(stderr, "hmm %d\n", p->boundY); 
  return p->boundY;

}

void drawPlayer(struct Player * p){
  al_draw_line(0.25 * SCREEN_WIDTH , 0.75 * SCREEN_HEIGHT, 0.25 * SCREEN_WIDTH + p->length,
      p->y + 0, al_map_rgb(255, 0, 0), 2);

  al_draw_rectangle(p->x- 5, p->y, p->x + 5, p->y - p->boundY, al_map_rgb(127,127,0), 1);

  
}
