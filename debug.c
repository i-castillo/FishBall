#include "runner.h"

void printBases(struct Base bases[4]){
  int i;
  for(i = 0; i < 4; i++){
    fprintf(stderr, "base %d: x: %d y: %d ", i,
        bases[i].x, bases[i].y /*,bases[i].personAt->ID */);
    if(bases[i].personAt != NULL){
        fprintf(stderr, "pAt x: %f y: %f \n", bases[i].personAt->x, 
            bases[i].personAt->y);
    }
    else{
    fprintf(stderr, "\n");
    }

  };

}

void printDistance(struct al_pointers * al_p){
  int i = 0;
  for(i = 0; i < SCREEN_HEIGHT; i+= 20){
    al_draw_textf(al_p->score, al_map_rgb(125,125,125), 200, i-10, 0, "%i", i);
    al_draw_line(0, i, SCREEN_WIDTH, i, al_map_rgb(255, 0, 255), 1 );

  };

};
