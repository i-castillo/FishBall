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

};
