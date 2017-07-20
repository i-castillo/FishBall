/* gameUtils.c */
#include "runner.h"
int collide(double xOne, double yOne, double xTwo, 
    double yTwo, double distance){


    return sqrt(pow(xTwo - xOne, 2) + pow(yTwo - yOne, 2)) <
            distance;


}

void calcLine(struct Runner * r, int bx, int by, int rx, int ry){

  r->angle = atan2(by-ry, bx-rx);

}

