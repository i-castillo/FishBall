/* drawRunner.c */
/* Initializes, moves and draws the runners. */
#include "runner.h"
#include <math.h>

/* Initializes the runners */
void initRunners(struct Runner r[], int numRunners){
  int i;
  for(i = 0; i < numRunners; i++){

    r[i].x = SCREEN_WIDTH / HALF;
    r[i].y = SCREEN_HEIGHT * 0.70;
    r[i].speed = 0;
    r[i].alive = 0;
    r[i].base = NULL;
    r[i].scored = 0;
    r[i].image = al_load_bitmap(RUNNER_IMAGE);    
    r[i].bmWidth = al_get_bitmap_width(r[i].image) /2;    
    r[i].bmHeight = al_get_bitmap_height(r[i].image) /2;
  };

}

/* Removes the runners from the screen, and resets their properties. */
void removeRunners(struct Runner r[], int numRunners){
  int i;
  for(i = 0; i < numRunners; i++){
    r[i].alive = 0;
    r[i].x = SCREEN_WIDTH / HALF;
    r[i].y = SCREEN_HEIGHT * 0.70;
    r[i].base = NULL;
    r[i].basestoGo = 0; 
    r[i].speed = 0;
  }
}

/* Moves the runners */
void moveRunners(struct Runner r[], int numRunners){
  int i;
  for(i = 0; i < numRunners; i++){
    if(r[i].alive == 1){
      if(fabs(r[i].x - (*r[i].base).x) > 2){

        r[i].x += r[i].speed * cos(r[i].angle);
        r[i].y += r[i].speed * sin(r[i].angle);

      }
      
      else if(r[i].y == SCREEN_HEIGHT * 0.70){
        fprintf(stderr, "htmmmm");
        (r[i]).basestoGo = 0;
        r[i].alive = 0;
        r[i].speed = 0;
        r[i].scored = 1;

      }
      else{
        
        r[i].x = (*r[i].base).x;
        r[i].y = (*r[i].base).y;

        if(r[i].basestoGo != 0 ){
          
          gotoNextBase(&r[i]);
          (r[i].basestoGo)--;

        }
        else{
        r[i].speed = 0;
        

        }
      }

    }
  }



}

/* Draws the runners */
void drawRunners(struct Runner r[], int numRunners){
  int i;
  for(i = 0; i < numRunners; i++){
    if(r[i].alive == 1){
      al_draw_bitmap(r[i].image, r[i].x - r[i].bmWidth, r[i].y - r[i].bmHeight, 0);
    }

  }

}

/* Destroys the allocated memory associated with each runner */
void destroyRunners(struct Runner r[], int numRunners){
  
  int i;
  for(i = 0; i < numRunners; i++){

    al_destroy_bitmap(r[i].image);
  }
}



