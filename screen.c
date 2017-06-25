/* screen.c */
#include "runner.h"
void drawScore(struct al_pointers * al_p, int score){
  
    al_draw_textf(al_p->score, al_map_rgb(125,125,125), 200, 10, 0, "%i", score );
    
}
