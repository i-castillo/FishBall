/* drawPlayer.c. */
#include "runner.h"
#include <math.h>
void initPlayer(struct Player * p){
  p->ID = PLAYER;
  p->x = INIT_PLAYER_X;
  p->y = INIT_PLAYER_Y;
  p->alive = 0;
//  p->length = PLAYER_LENGTH;
  p->speed = 0;
  p->score = 0;
  p->power = 0;
  calculateBound(p);

}

void movePlayer(struct Player * p){

  p->y += p->speed;
  if(p->y < INIT_PLAYER_Y - p->boundY){
    p->speed = 0;
    p->y = INIT_PLAYER_Y - p->boundY;
  }
  else if(p->y > (INIT_PLAYER_Y + p->boundY)){
    
    p->y = INIT_PLAYER_Y + p->boundY;
    p->speed = 0;
  }
   p->x = calcDeltaX(p);
  }



void setPower(struct Player * p, int power){
  if(p->alive == 1){
  p->power = 1 * power;
  
  }

  
}

void setSpeed(struct Player * p, int speed){
  if(p->alive == 1){
    p->speed = speed;

  }
    
}

void setAlive(struct Player * p, int alive){
  p->alive = alive;
}

void calculateBound(struct Player * p){

//  p->boundY = sqrt((0.10 * SCREEN_WIDTH) * SCREEN_WIDTH /4 + 
//      0.05 * SCREEN_WIDTH * 0.05 * SCREEN_WIDTH);
  p->boundY = PLAYER_LENGTH;

}

int calcDeltaX(struct Player * p){
  int P_L = (int) PLAYER_LENGTH;
  double dist = p->y - PIVOT_Y; //ranges from -86 to 86. PLAYER_LENGTH = 150. 
  double dr = P_L * cos(asin(dist / P_L ));

  //asin prints 'nan';
  return PIVOT_X + dr;

}

void drawPlayer(struct Player * p){

  al_draw_line(PIVOT_X , PIVOT_Y,  p->x, p->y, al_map_rgb(255, 0, 0), 2);
  //  fprintf(stderr, "hmmmsadf %d\n", p->y);
  al_draw_rectangle(p->x -5, p->y, p->x + 5, p->y - p->boundY, al_map_rgb(127,127,0), 1);
 // fprintf(stderr, "%d\n",  (int)sqrt(pow(p->x - PIVOT_X, 2) + (pow(p->y-PIVOT_Y,2))));



}

void drawPointVector(struct Player * p, struct Ball * b){
  
  int deltaX = p->x - PIVOT_X;
  int deltaY = p->y - PIVOT_Y;
  al_draw_line(p->x, p->y, p->x + deltaY, p->y - deltaX, al_map_rgb(0,0,
        255), 3); 

// al_draw_line(SCREEN_WIDTH/2, INIT_PLAYER_Y, b->x, b->y, al_map_rgb(255, 0, 255), 3);

};
