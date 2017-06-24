/* entities.h */
#ifndef ENTITIES_H
#define ENTITIES_H
#include "runner.h"

#define PLAYER 0
#define BALL 1
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

struct Ball {
  int ID;
  int x;
  int y;
  int speed;
  

};


void initPlayer(struct Player * p);
void drawPlayer(struct Player * p);
void initBall(struct Ball * b);
void drawBall(struct Ball * b);
void throwBall(struct Ball * b);


#endif
