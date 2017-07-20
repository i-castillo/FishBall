/* catchers.c */
/* Includes subroutines to intialize catchers, move catchers,
   and draw catchers, randomize the location of catchers. */ 
#include "runner.h"
#include <math.h>

/* Initializes the catchers. */
void initCatchers(struct Catcher c[], int numCatchers){
  int i;
  for(i = 0; i < numCatchers; i++){

    c[i].x = SCREEN_WIDTH /2;
    c[i].y = SCREEN_HEIGHT /2;
    c[i].speed = 0;
    c[i].alive = 1;
    c[i].catched = 0;
    c[i].image = al_load_bitmap(CATCHER_IMAGE);
    c[i].bmWidth = al_get_bitmap_width(c[i].image) /2;
    c[i].bmHeight = al_get_bitmap_height(c[i].image) /2;

  }


}

/* Randomizes the location of the catchers */
void randomizeCatchers(struct Catcher c[], int numCatchers, int radius){

  /* How the algorithm works is as follows: Randomizes a players position. If
     the randomized position is too close to another catcher, then re-randomize
     the position. */
  int i;
  int j;
  int goodRandom;

  for(i = 0; i < numCatchers; i++){
    goodRandom = 0;

    do{
      c[i].x = rand() % HALF_SCREEN_WIDTH + EIGHTH_SCREEN_WIDTH;
      c[i].y = rand() % QUARTER_SCREEN_HEIGHT + QUARTER_SCREEN_HEIGHT;
      goodRandom = 1;

      /* Ensure that it the random is a "goodRandom". */
      for(j = 0; j < numCatchers; j++){

        if(i != j && collide(c[i].x, c[i].y, c[j].x, c[j].y, radius))
          goodRandom = 0;

      }
    }
    while(goodRandom == 0);
    c[i].catched = 0;
  }
}


/* Moves the catchers */
void moveCatchers(struct Catcher c[], int numCatchers, int moveDistance){

  /* How the catchers mover is like so. They will randomly move forward or
     backward a few distances */ 
  int i;
  for(i = 0; i < numCatchers; i++){
    int r = rand() % 2; //an integer between 0 and 1.
    if(r == 0){
      c[i].x += moveDistance;
    }
    else if(r == 1){
      c[i].x -= moveDistance;
    }
    c[i].direction = r;
  }

}

/* Draws the catchers */
void drawCatchers(struct Catcher c[], int numCatchers){
  int i;
  for(i = 0; i < numCatchers; i++){
    if(c[i].alive == 1){
      if(c[i].direction == 1){
        al_draw_bitmap(c[i].image, c[i].x - c[i].bmWidth, c[i].y -
            c[i].bmHeight, 0);

      }
      else {
        al_draw_bitmap(c[i].image, c[i].x - c[i].bmWidth, c[i].y - 
            c[i].bmHeight, ALLEGRO_FLIP_HORIZONTAL);

      }
    }

  }
}

/* Destroys the memory allocated with catchers */
void destoryCatchers(struct Catcher c[], int numCatchers){

  int i;
  for(i = 0; i < numCatchers; i++){
    al_destroy_bitmap(c[i].image);
  }
}



