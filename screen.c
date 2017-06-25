/* screen.c */
#include "runner.h"
void drawScore(struct al_pointers * al_p, int score){
  
    al_draw_textf(al_p->score, al_map_rgb(125,125,125), 200, 10, 0, "%i", score );
    
}

void drawBalls(int ballsRem){
  int i;
  for(i = 0; i < ballsRem; i++){
    al_draw_filled_circle(20 * i + 10, 40, 5, al_map_rgb(100,225, 100));

  }

}

void drawPowerBar(int power){
  int i;
  for(i = 0; i < power; i++){
    al_draw_filled_rectangle(i * 50 + 10, 750, i * 50 + 60, 780, 
        al_map_rgb(i * 25, i * 25, 120));
  }

}
