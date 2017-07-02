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
#define PIVOT_X       0.25 * SCREEN_WIDTH
#define PIVOT_Y       0.75 * SCREEN_HEIGHT
#define EXTRA_BAT ONE_TWENTIETH * SCREEN_WIDTH
#define INIT_PLAYER_X SCREEN_WIDTH / HALF + EXTRA_BAT
#define INIT_PLAYER_Y PIVOT_Y
#define OFFSET_LENGTH SCREEN_WIDTH / QUARTER
#define PLAYER_LENGTH INIT_PLAYER_X - PIVOT_X
struct Player {

  int ID; 
  double x;
  double y;
  int health;
  int boundY;
  int boundX;
  int speed;
  int alive;
//  int length;
  int score;
  int power;


};

struct Ball {
  int ID;
  double x;
  double y;
  int speed;
  double angle;
  int alive;
  int hit;
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
  int basestoGo;
};

struct Base {
  int x;
  int y;
  struct Runner * personAt;
  struct Base * nextbase;
  
};

struct Catcher {
  char ID;
  double x;
  double y;
  double speed;
  double angle;
  struct Base * base;
  int alive; //can control
  int catched;

};


int calcDeltaX(struct Player * p);
void calculateBound(struct Player * p);
void initPlayer(struct Player * p);
void drawPlayer(struct Player * p);
void movePlayer(struct Player * p);
void resetPlayer(struct Player * p);
void setAlive(struct Player * p, int alive);
void setPower(struct Player * p, int power);
void initBall(struct Ball * b);
void drawBall(struct Ball * b);
void throwBall(struct Ball * b);
void moveBall(struct Ball * b);
int hitBall(struct Player * p, struct Ball * b);
void initRunners(struct Runner runners[4]);
void drawRunners(struct Runner runners[4]);
void moveRunners(struct Runner runners[4]);
void initBases(struct Base bases[4] );
void gotoNextBase(struct Runner * r);
void loadBase(struct Base bases[4], struct Runner runners[4], int runner, int
    numBases);

void gotoBase(struct Runner * r, struct Base * base);
void calcLine(struct Runner * r, int bx, int by, int rx, int ry);

/* debug */
void drawField(struct Base bases[4]);
void printBases(struct Base bases[4]);
void setSpeed(struct Player * p, int speed);
void drawPointVector(struct Player * p, struct Ball * b);
void initCatchers(struct Catcher c[4]);
void moveCatchers(struct Catcher c[4]);
void drawCatchers(struct Catcher c[4]);
void randomizeCatchers(struct Catcher c[4]);
void drawCatcherswithPos(ALLEGRO_FONT * f, struct Catcher c[4]);
struct Catcher * checkIfCatch(struct Catcher c[4], struct Ball * b);
int catchBall(struct Catcher c[4], struct Ball * b);
int stillrunning(struct Catcher c[4]);
void removeRunners(struct Runner r[4]);
void clearBases(struct Base bases[4]);
#endif
