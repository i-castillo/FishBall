/* drawRunner.c */
#include "runner.h"
#include <math.h>
void initRunners(struct Runner r[4]){
  int i;
  for(i = 0; i < 4; i++){
    r[i].ID = i;
    r[i].x = SCREEN_WIDTH / HALF;
    r[i].y = SCREEN_HEIGHT * 0.90;
    r[i].speed = 5;
    r[i].alive = 0;
    r[i].base = NULL;
  };

}

void moveRunners(struct Runner r[4]){
  int i;
  for(int i = 0; i < 4; i++){
    if(r[i].alive == 1){
    if(fabs(r[i].x - (*r[i].base).x) > 2){
      
        r[i].x += r[i].speed * cos(r[i].angle);
        r[i].y += r[i].speed * sin(r[i].angle);

    }
    else{
      r[i].x = (*r[i].base).x;
      r[i].y = (*r[i].base).y;

    }
    
    }
  };

  

}

void drawRunners(struct Runner r[4]){
  int i;
  for(i = 0; i < 4; i++){
    if(r[i].alive == 1){
      al_draw_filled_triangle(r[i].x, r[i].y, r[i].x + 5, r[i].y + 5,
          r[i].x + 10, r[i].y, al_map_rgb(0,255, 255));
    }

  }

}
