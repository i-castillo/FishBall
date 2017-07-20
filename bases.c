/* bases.c */
/* Initializes the bases, clears the bases, and draws the bases. */
#include "runner.h"
#include <math.h>

/* Initializes the bases. Assumed the number of bases is '4'. */
void initBases(struct Base base[], int numBases){

  if(numBases != 4){
    return; 
  }

  double basewidth = SCREEN_WIDTH/3 * sqrt(2);
  base[0].x = SCREEN_WIDTH / HALF;
  base[0].y = SCREEN_HEIGHT * 0.70;
  base[0].personAt = NULL;
  base[0].nextBase = &base[1];

  base[1].x = base[0].x + basewidth * sqrt(2) / 2 ;
  base[1].y = base[0].y - basewidth * sqrt(2) / 2 ;
  base[1].personAt = NULL;
  base[1].nextBase = &base[2];

  base[2].x = base[0].x;
  base[2].y = base[0].y - 2 * basewidth / sqrt(2);
  base[2].personAt = NULL;
  base[2].nextBase = &base[3];

  base[3].x = base[0].x - basewidth / sqrt(2);
  base[3].y = base[0].y - basewidth / sqrt(2);
  base[3].personAt = NULL;
  base[3].nextBase = &base[0];


}

/* Initializes the bases */
void clearBases(struct Base bases[], int numBases){
  int i;
  for(i = 0; i < numBases; i++){
    bases[i].personAt = NULL;
  }
}



/* draws the bases. Assumes '4' bases. */
void drawBases(struct Base bases[], int numBases){

  if(numBases != 4){
    return;
  }
  al_draw_line(bases[0].x, bases[0].y, bases[1].x, bases[1].y,
      al_map_rgb(255,255,255), 5);
  al_draw_line(bases[1].x, bases[1].y, bases[2].x, bases[2].y,
      al_map_rgb(255,255,255), 5);
  al_draw_line(bases[2].x, bases[2].y, bases[3].x, bases[3].y,
      al_map_rgb(255,255,255), 5);
  al_draw_line(bases[3].x, bases[3].y, bases[0].x, bases[0].y,
      al_map_rgb(255,255,255), 5);

}
