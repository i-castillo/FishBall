/* drawField.c */
#include "runner.h"
#include <math.h>
void initBases(struct Base base[4]){

  int basewidth = sqrt(2) * SCREEN_WIDTH / 2 - 10; 
  base[0].x = SCREEN_WIDTH / HALF;
  base[0].y = SCREEN_HEIGHT * 0.90;
  base[0].personAt = NULL;
  base[0].nextbase = &base[1];
  
  
  base[1].x = base[0].x + basewidth / sqrt(2);
  base[1].y = base[0].y - basewidth / sqrt(2);
  base[1].personAt = NULL;
  base[1].nextbase = &base[2];

  base[2].x = base[0].x;
  base[2].y = base[0].y - 2 * basewidth / sqrt(2);
  base[2].personAt = NULL;
  base[2].nextbase = &base[3];

  base[3].x = base[0].x - basewidth / sqrt(2);
  base[3].y = base[0].y - basewidth / sqrt(2);
  base[3].personAt = NULL;
  base[3].nextbase = &base[0];


};

void loadBase (struct Base bases[4], struct Runner r[4], int num, int
    numBases){

  num = num % 4;
  
  int i;
  for(i = 3; i > 0; i--){
    if(bases[i].personAt != NULL){

      gotoBase(bases[i].personAt, bases[i].nextbase);
      (bases[i].personAt)->basestoGo = numBases - 1;

    }

  } 
  r[num].basestoGo = numBases - 1;

  gotoBase(&r[num], &bases[1]);
  


}

void gotoNextBase(struct Runner * r){
  r->base->personAt = NULL;
  gotoBase(r, r->base->nextbase);
 // fprintf(stderr, "going to next base\n");
};

void gotoBase(struct Runner * r, struct Base * base){
  if(r != NULL){

    r->alive = 1;
    r->base = base;
    base->personAt = r;
   // fprintf(stderr, "going to base %d %d\n", r->base->x, r->base->y);
    
    calcLine(r, r->base->x, r->base->y, r->x, r->y);
  }
}

void calcLine(struct Runner * r, int bx, int by, int rx, int ry){

  r->angle = atan2(by-ry, bx-rx);

}

void drawField(struct Base bases[4]){
  al_draw_line(bases[0].x, bases[0].y, bases[1].x, bases[1].y,
      al_map_rgb(255,255,255), 1);

  al_draw_line(bases[1].x, bases[1].y, bases[2].x, bases[2].y,
      al_map_rgb(255,255,255), 1);
 al_draw_line(bases[2].x, bases[2].y, bases[3].x, bases[3].y,      al_map_rgb(255,255,255), 1);
 al_draw_line(bases[3].x, bases[3].y, bases[0].x, bases[0].y,      al_map_rgb(255,255,255), 1);

}
