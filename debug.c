/* debug.c */
#include "entities.h"

/* Print the location of the bases, thier next base, and the person at the 
   base, if one exists. */
void printBases(struct Base bases[], int numBases){
  int i;
  for(i = 0; i < numBases; i++){
    fprintf(stderr, "base %d: x: %d y: %d nextbase x: %d y: %d", i,
        bases[i].x, bases[i].y, bases[i].nextBase->x, bases[i].nextBase->y);
    if(bases[i].personAt != NULL){
        fprintf(stderr, "pAt x: %f y: %f \n", bases[i].personAt->x, 
            bases[i].personAt->y);
    }
    else{
    fprintf(stderr, "\n");
    }
    
  }

}
void printRunners(struct Runner r[], int numRunners){
    
  int i;
  for(i = 0; i < numRunners; i++){
    fprintf(stderr, "runner %d: x: %f, y: %f.\n", i, r[i].x, r[i].y);
  }
}

/* Prints lines with number on them starting from the top, to the bottom, with
   20 pixel increments */
void printDistance(struct al_pointers * al_p){
  int i = 0;
  for(i = 0; i < SCREEN_HEIGHT; i+= 20){
    al_draw_textf(al_p->score, al_map_rgb(125,125,125), 200, i-10, 0, "%i", i);
    al_draw_line(0, i, SCREEN_WIDTH, i, al_map_rgb(255, 0, 255), 1 );

  }

}


/* Draws a "protractor" on the screen. */
void drawAngle(){
  int i;
  for(i = 0; i < 180; i+= 5){

    al_draw_circle(SCREEN_WIDTH/2 *(1 + cos(i * 3.14159 / 180 )), SCREEN_WIDTH/2
        * (1.8 - sin(i * 3.14159 / 180)),
            2, al_map_rgb(255, 0, 255), 2);
  }

}
/* Draws a circle around the catchers, designating their collision range. */
void drawBoundOnCatchers(struct Catcher c[], int numCatchers){
  int i;
  for(i = 0; i < numCatchers; i++){
    al_draw_circle(c[i].x, c[i].y, 25, al_map_rgb(0,0,0), 2);
  }

    

}

/* Draws catchers with positions. DEBUG //TODO */
void drawCatcherswithPos(ALLEGRO_FONT * f, struct Catcher c[4]){
  int i;
  for(i = 0; i < 4; i++){
    if(c[i].alive == 1){
      al_draw_textf(f, al_map_rgb(123,123,151), c[i].x, c[i].y,
          0, "%i %f", i, (c[i].angle));

      if(c[i].direction == 1){
        al_draw_bitmap(c[i].image, c[i].x - 20, c[i].y - 20, 0);

      }
      else {
        al_draw_bitmap(c[i].image, c[i].x - 20, c[i].y - 20,
            ALLEGRO_FLIP_HORIZONTAL);

      }

    }

  }

}

/* Draws a line pointing to direction of hit. */
void drawPointVector(struct Player * p, struct Ball * b){

  int deltaX = p->x - PIVOT_X;
  int deltaY = p->y - PIVOT_Y;
  al_draw_line(p->x, p->y, p->x + deltaY, p->y - deltaX, al_map_rgb(0,0,
        255), 3); 

  // al_draw_line(SCREEN_WIDTH/2, INIT_PLAYER_Y, b->x, b->y, al_map_rgb(255, 0, 255), 3);

};

