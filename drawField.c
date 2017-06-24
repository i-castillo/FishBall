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

void loadBase (struct Base bases[4], struct Runner runners[4], int * runner, int
    numBases){
  if(*runner > 4){
    return;
  }
  if(*runner > 3){
    *runner = 1;
  }else{
    (*runner)++;
  }
  while(numBases > 0){
       if(bases[3].personAt != NULL){
    fprintf(stderr, "going to base 0");
     
    gotoBase(bases[3].personAt, &bases[0]);
   }   if(bases[2].personAt != NULL){
    fprintf(stderr, "going to base 3");
     
    gotoBase(bases[2].personAt, &bases[3]);
   }



   if(bases[1].personAt != NULL){
    fprintf(stderr, "going to base 2");
    gotoBase(bases[1].personAt, &bases[2]);
   }
  numBases--;
  }
   gotoBase(&runners[*runner], &bases[1]); 
  
  
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
