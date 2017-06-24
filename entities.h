/* entities.h */
#ifndef ENTITIES_H
#define ENTITIES_H
#include "runner.h"

#define PLAYER 0
#define BALL 1
#define HALF 2
#define QUARTER 4
#define THREE_QUARTER 0.75
#define ONE_TWENTIETH 0.05
#define INIT_PLAYER_X SCREEN_WIDTH / HALF
#define INIT_PLAYER_Y SCREEN_HEIGHT * THREE_QUARTER
#define PLAYER_LENGTH SCREEN_WIDTH / QUARTER + ONE_TWENTIETH * SCREEN_WIDTH

struct Player {

  int ID; 
  int x;
  int y;
  int health;
  int boundY;
  int boundX;
  int speed;
  int alive;
  int length;


};

struct Ball {
  int ID;
  int x;
  int y;
  int speed;
  double angle;
  int alive;
  int color;

};

struct Runner {
  char ID;
  double x;
  double y;
  int speed;
  double angle;
  struct Base * base;
  int alive; //can control

};

struct Base {
  int x;
  int y;
  struct Runner * personAt;
};



void calculateBound(struct Player * p);
void initPlayer(struct Player * p);
void drawPlayer(struct Player * p);
void movePlayer(struct Player * p);
void resetPlayer(struct Player * p);
void setSpeed(struct Player * p, int speed);
void initBall(struct Ball * b);
void drawBall(struct Ball * b);
void throwBall(struct Ball * b);
void moveBall(struct Ball * b);
int hitBall(struct Player * p, struct Ball * b);
void initRunners(struct Runner runners[4]);
void drawRunners(struct Runner runners[4]);
void moveRunners(struct Runner runners[4]);
void initBases(struct Base bases[4] );
void loadBase(struct Base bases[4], struct Runner runners[4], int runner, int
    numBases);

void gotoBase(struct Runner * r, struct Base * base);
void calcLine(struct Runner * r, int bx, int by, int rx, int ry);

/* debug */
void drawField(struct Base bases[4]);
void printBases(struct Base bases[4]);

#endif
