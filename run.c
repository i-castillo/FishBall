/* checks if there is still a runner running. */
#include "runner.h"
int stillRunning(struct Runner r[], int numRunners){
  int i;
  for(i = 0; i < numRunners; i++){
    if(r[i].speed != 0){
      return 1;
    }
  }
  return 0;
}

/* Loads the bases */
void loadBase (struct Base bases[], int numBases, struct Runner r[],
    int numRunners, int runnerIndex, int speed, int basesToRun){

  runnerIndex = runnerIndex % numRunners;

  int i;
  for(i = numBases-1; i > 0; i--){
    if(bases[i].personAt != NULL){
      (bases[i].personAt)->speed = speed;
      gotoBase(bases[i].personAt, bases[i].nextBase);
      (bases[i].personAt)->basestoGo = basesToRun - 1;

    }

  }
  r[runnerIndex].speed = speed;
  r[runnerIndex].basestoGo = basesToRun - 1;

  gotoBase(&r[runnerIndex], &bases[1]);

}

/* Makes the runner go to the next base */
void gotoNextBase(struct Runner * r){
  r->base->personAt = NULL;
  gotoBase(r, r->base->nextBase);
  
}

/* goes to the next base. */
void gotoBase(struct Runner * r, struct Base * base){
  if(r != NULL){

    r->alive = 1;
    r->base = base;
    base->personAt = r;
    calcLine(r, r->base->x, r->base->y, r->x, r->y);

  }
}



