#include "runner.h"
void printBases(struct Base bases[4]){
  int i;
  for(i = 0; i < 4; i++){
    fprintf(stderr, "base %d: x: %d y: %d nextbase x: %d y: %d", i,
        bases[i].x, bases[i].y, bases[i].nextbase->x, bases[i].nextbase->y /*,bases[i].personAt->ID */);
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

void drawAngle(){
  double i;
  for(i = 0; i < 3.15; i+= 0.1){
    al_draw_circle(SCREEN_WIDTH/2 *(1 + cos(i)), SCREEN_WIDTH/2 * (1.8 - sin(i)),
            2, al_map_rgb(255, 0, 255), 2);
  };

};

void printAngle(){
  int i;
  double pi = 3.141592;
  for(i = -OFFSET_LENGTH; i < OFFSET_LENGTH; i+=3){
    double angle = atan2((double)i, OFFSET_LENGTH) + acos(0);
    angle = angle * 180.0 / pi; 
    if(angle > 85 && angle < 90){
    fprintf(stderr, "%#2f %d ", angle, i);

    }
    

  };

};
