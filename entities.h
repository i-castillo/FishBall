/* entities.h */
#ifndef ENTITIES_H
#define ENTITIES_H
#include "runner.h"

#define PLAYER 0
#define HALF 2
#define HEALTH 200
#define BOUND 10
struct Player {

  int ID; 
  int x;
  int health;
  int boundY;
  int boundX;

};


void initPlayer(struct Player * p);
void drawPlayer(struct Player * p);

#endif
