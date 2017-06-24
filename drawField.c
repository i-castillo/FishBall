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

void loadBase (struct Base bases[4], struct Runner runners[4], int runner, int
    numBases){

    runner %= 4;
  
   
  while(numBases > 0){
    if(bases[3].personAt != NULL){
      fprintf(stderr, "%d going to base 0\n", runner);

      gotoBase(bases[3].personAt, &bases[0]);
      bases[0].personAt = NULL;
    }
    if(bases[2].personAt != NULL){
      fprintf(stderr, "%d going to base 3\n", runner);

      gotoBase(bases[2].personAt, &bases[3]);
    }

    if(bases[1].personAt != NULL){
      fprintf(stderr, "%d going to base 2\n", runner);
      gotoBase(bases[1].personAt, &bases[2]);
    }
    numBases--;
  }
  gotoBase(&runners[runner], &bases[1]); 
      fprintf(stderr, "%d going to base 1\n", runner);


  
}

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
