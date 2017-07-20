/* entities.h */
#ifndef ENTITIES_H
#define ENTITIES_H

#include "runner.h"
struct Game {
  int hasSound;
  int highScore;
  int difficulty;
};

struct al_pointers {
   	ALLEGRO_DISPLAY *display;
  	ALLEGRO_EVENT_QUEUE *event_queue;
  	ALLEGRO_TIMER *timer;
    ALLEGRO_FONT * score;  
};

struct Player {

  double x;
  double y;
  int health;
  int boundY;
  int boundX;
  int speed;
  int alive;
  int score;
  int power;
  ALLEGRO_BITMAP * image;

};

struct Ball {

  double x;
  double y;
  int speed;
  double angle;
  int alive;
  int hit;
  int color;
  int bmHeight;
  int bmWidth;
  ALLEGRO_BITMAP * image;
  
};

struct Runner {
  int direction;

  double x;
  double y;
  int speed;
  double angle;
  struct Base * base;
  int alive; //can control
  int basestoGo;
  int bmWidth;
  int bmHeight;
  int scored;
  ALLEGRO_BITMAP * image;
  
};

struct Base {
  int x;
  int y;
  struct Runner * personAt;
  struct Base * nextBase;
  
};

struct Catcher {
  
  double x;
  double y;
  double speed;
  double angle;
  struct Base * base;
  int alive; //can control
  int catched;
  int direction;
  int bmWidth;
  int bmHeight;
  ALLEGRO_BITMAP * image;

};

/* game.c */
int init_game( struct al_pointers * al_p, int width, int height);
int destroy_allegro(struct al_pointers * al_p);
void updateDifficulty(struct Game * g, int SPEED[], int size);

/* runner.c */
void initRunners(struct Runner r[], int numRunners);
void removeRunners(struct Runner r[], int numRunners);
void moveRunners(struct Runner r[], int numRunners);
void drawRunners(struct Runner r[], int numRunners);
void destoryRunners(struct Runner r[], int numRunners);

/* ball.c */
void initBall(struct Ball * b);
void moveBall(struct Ball * b);
void drawBall(struct Ball * b);
void destoryBall(struct Ball * b);

/* bases.c */
void initBases(struct Base base[], int numBases);
void clearBases(struct Base bases[], int numBases);
void drawBases(struct Base bases[], int numBases);

/* catchers.c */
void initCatchers(struct Catcher c[], int numCatchers);
void randomizeCatchers(struct Catcher c[], int numCatchers, int radius);
void moveCatchers(struct Catcher c[], int numCatchers, int moveDistance);
void drawCatchers(struct Catcher c[], int numCatchers);
void destoryCatchers(struct Catcher c[], int numCatchers);

/* player.c */
void initPlayer(struct Player * p);
void movePlayer(struct Player * p);
void setPower(struct Player * p, int power);
void setSpeed(struct Player * p, int speed);
void setAlive(struct Player * p, int alive);
void resetPlayer(struct Player * p);
int calcDeltaX(struct Player * p);
void drawPlayer(struct Player * p);

/* baseball.c */
void throwBall(struct Ball * b, int speed);
int catchBall(struct Catcher c[], int numCatchers, struct Ball * b, int radius);
int hitBall(struct Player * p, struct Ball * b);
void checkScore(struct Runner r[], int numRunners, int * score);

/* gameUtils.c */
int collide(double xOne, double yOne, double xTwo, double yTwo, double distance);
void calcLine(struct Runner * r, int bx, int by, int rx, int ry);

/* debug.c */
void printBases(struct Base bases[], int numBases);
void printRunners(struct Runner r[], int numRunners);
void printDistance(struct al_pointers * al_p);
void drawAngle();
void drawBoundOnCatchers(struct Catcher c[], int numCatchers);
void drawCatcherswithPos(ALLEGRO_FONT * f, struct Catcher c[4]);
void drawPointVector(struct Player * p, struct Ball * b);

/* run.c */
int stillRunning(struct Runner r[], int numRunners);
void loadBase (struct Base bases[], int numBases, struct Runner r[],
    int numRunners, int runnerIndex, int speed, int basesToRun);
void gotoNextBase(struct Runner * r);
void gotoBase(struct Runner * r, struct Base * base);

/* loop.c */
void loop(struct al_pointers * al_p, struct Game * g);

/* screen.c */
void drawScore(struct al_pointers * al_p, int score);
void drawBackground(ALLEGRO_BITMAP * image);
void drawBalls(int ballsRem);
void drawSpeed(ALLEGRO_BITMAP * img, struct al_pointers * al_p, int speed);
void drawPowerBar(int power);
void loadStart(struct al_pointers * al_p, struct Game * g);
void loadSettings(struct al_pointers * al_p, struct Game * g);
void loadRules(struct al_pointers * al_p);
void loadGameOver(struct al_pointers * al_p, int * finished);


#endif
