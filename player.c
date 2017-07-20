/* player.c. */
/* Initializes the player, moves the player, and draws the player. Also provides
 * some setter methods for player-related fields. */
#include "runner.h"
#include <math.h>

/* Initializes the player */
void initPlayer(struct Player * p){
  p->x = INIT_PLAYER_X;
  p->y = INIT_PLAYER_Y;
  p->alive = 0;
  p->speed = 0;
  p->power = 0;
  p->image = al_load_bitmap(BAT_IMAGE);
  p->boundY = PLAYER_LENGTH;


}

/* moves the player */
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


/* Sets the power */
void setPower(struct Player * p, int power){
  if(p->alive == 1){
    p->power = 1 * power;

  }

}

/* Sets the speed */
void setSpeed(struct Player * p, int speed){
  if(p->alive == 1){
    p->speed = speed;

  }

}

/* Sets the alive status */
void setAlive(struct Player * p, int alive){
  p->alive = alive;
}

/* Resets the position of the player */
void resetPlayer(struct Player * p){
  p->y = INIT_PLAYER_Y;
  p->speed = 0;
  p->power = 0;

};


/* Moves the x-value depending on the y-value */
int calcDeltaX(struct Player * p){
  int P_L = (int) PLAYER_LENGTH;
  double dist = p->y - PIVOT_Y; //ranges from -86 to 86. PLAYER_LENGTH = 150. 
  double dr = P_L * cos(asin(dist / P_L ));

  return PIVOT_X + dr;

}

/* Draws the player */
void drawPlayer(struct Player * p){

  al_draw_scaled_rotated_bitmap(p->image, 0, 0, PIVOT_X, PIVOT_Y, 2, 1,
      atan2(  p->y - PIVOT_Y, p->x - PIVOT_X), 0);

  /* Primitive draw */
  // al_draw_line(PIVOT_X , PIVOT_Y,  p->x, p->y, al_map_rgb(255, 0, 0), 2);
  //  al_draw_rectangle(p->x -5, p->y, p->x + 5, p->y - p->boundY, al_map_rgb(127,127,0), 1);




}
/* Destorys the memory associated with the player */
void destoryPlayer(struct Player * p){
  al_destroy_bitmap(p->image);
 }
