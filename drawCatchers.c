/* drawCatchers */
#include "runner.h"
#include <math.h>
void initCatchers(struct Catcher c[4]){
  int i;
  for(i = 0; i < 4; i++){
    c[i].ID = i;
    c[i].x = SCREEN_WIDTH / HALF;
    c[i].y  = SCREEN_HEIGHT / HALF;
    c[i].speed = 0;
    c[i].alive = 1;
    c[i].catched = 0;

  }


}
int stillrunning(struct Catcher c[4]){
  int i;
  for(i = 0; i < 4; i++){
    if(c[i].speed != 0){
      return 1;
    }
  }
  return 0;
}

void randomizeCatchers(struct Catcher c[4]){

  c[0].x = rand() % (SCREEN_WIDTH / 2)  + SCREEN_WIDTH / 8;
  c[0].y = rand() % (SCREEN_HEIGHT / 4) + SCREEN_HEIGHT / 4;

  c[0].catched = 0;

  c[1].x = rand() % (SCREEN_WIDTH / 2) + SCREEN_WIDTH / 2;
  c[1].y = rand() % (SCREEN_HEIGHT)/4 + SCREEN_HEIGHT / 4;
  if(c[1].x < SCREEN_WIDTH/2){
 //   c[1].angle *= -1;
  }

  c[1].catched = 0;

  c[2].x = rand() % (SCREEN_WIDTH / 2)  + SCREEN_WIDTH / 8;
  c[2].y = rand() % (SCREEN_HEIGHT)/4 + SCREEN_HEIGHT / 4;

  if(c[2].x < SCREEN_WIDTH/2){
 //   c[2].angle *= -1;
  }

  c[2].catched = 0;

  c[3].x = rand() % (SCREEN_WIDTH / 2)  + SCREEN_WIDTH / 2;
  c[3].y = rand() % (SCREEN_HEIGHT)/4  + SCREEN_HEIGHT / 4;

  if(c[3].x < SCREEN_WIDTH/2){
 //   c[3].angle *= -1;
  }

  c[3].catched = 0;

}

struct Catcher * checkIfCatch(struct Catcher c[4], struct Ball * b){
  int i;
  for(i = 0; i < 4; i++){
    if(fabs(b->angle - c[i].angle) < 0.25){

      c[i].catched = 1;
      return &c[i];
    }

  }
  return 0;
}

void moveCatchers(struct Catcher c[4]){
  
}

void drawCatchers(struct Catcher c[4]){
  int i;
  for(i = 0; i < 4; i++){
    if(c[i].alive == 1){
      al_draw_filled_triangle(c[i].x, c[i].y, c[i].x + 5, c[i].y + 5,
          c[i].x + 10, c[i].y, al_map_rgb(0,50, 190));
    }

  }
}

void drawCatcherswithPos(ALLEGRO_FONT * f, struct Catcher c[4]){
  int i;
  for(i = 0; i < 4; i++){
    if(c[i].alive == 1){
      al_draw_textf(f, al_map_rgb(123,123,151), c[i].x, c[i].y,
          0, "%i %f", i, (c[i].angle));
      al_draw_filled_triangle(c[i].x, c[i].y, c[i].x + 5, c[i].y + 5,
          c[i].x + 10, c[i].y, al_map_rgb(0,50, 190));
    }

  }


}




