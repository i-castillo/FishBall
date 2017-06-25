/* drawField.c */
#include "runner.h"
#include <math.h>
void initBases(struct Base base[4]){
  base[0].x = SCREEN_WIDTH / HALF;
  base[0].y = SCREEN_HEIGHT * 0.90;
  base[0].personAt = NULL;

  base[1].x = SCREEN_WIDTH * 0.85;
  base[1].y = SCREEN_HEIGHT / HALF;
  base[1].personAt = NULL;

  base[2].x = SCREEN_WIDTH / HALF;
  base[2].y = SCREEN_HEIGHT * 0.35;
  base[2].personAt = NULL;

  base[3].x = SCREEN_WIDTH * 0.15;
  base[3].y = SCREEN_HEIGHT / HALF;
  base[3].personAt = NULL;


};

void loadBase (struct Base bases[4], struct Runner r[4], int runner, int
    numBases){

  runner %= 4;
  gotoBase(&r[runner], &bases[0]); 
  int i;
  for(i = 0; i < 4; i++){
    r[i].basestoGo = numBases;
    gotoNextBase(&r[i]);

  }

}

void gotoNextBase(struct Runner * r){
  (r->basestoGo)--;
 // if(r->base == 3){
    gotoBase(r, (r->base)-3);
  }
  else{

    gotoBase(r, (r->base)+1);
  }


};

void gotoBase(struct Runner * r, struct Base * base){
  r->alive = 1;
  r->base = base;
  base->personAt = r;
  calcLine(r, r->base->x, r->base->y, r->x, r->y);
}

void calcLine(struct Runner * r, int bx, int by, int rx, int ry){



  // double ratio = ((double)(by - ry) / (bx - rx));


  r->angle = atan2(by-ry, bx-rx);

}

void drawField(struct Base bases[4]){
  al_draw_line(bases[0].x, bases[0].y, bases[1].x, bases[1].y,
      al_map_rgb(255,255,255), 1);

  al_draw_line(bases[1].x, bases[1].y, bases[2].x, bases[2].y,
      al_map_rgb(255,255,255), 1);
  al_draw_line(bases[2].x, bases[2].y, bases[3].x, bases[3].y,
      al_map_rgb(255,255,255), 1);
  al_draw_line(bases[3].x, bases[3].y, bases[0].x, bases[0].y,
      al_map_rgb(255,255,255), 1);

};
