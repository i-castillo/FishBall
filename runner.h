/* runner.h */
#ifndef RUNNER_H
#define RUNNER_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <stdio.h>
#include "entities.h"
#include "play.h"

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 800
#define FPS 60

struct al_pointers {
   	ALLEGRO_DISPLAY *display;
  	ALLEGRO_EVENT_QUEUE *event_queue;
  	ALLEGRO_TIMER *timer;
    ALLEGRO_FONT * score;  
};
int loop(struct al_pointers * al_p);
int init_game( struct al_pointers * al_p, int width, int height);
int destroy_allegro(struct al_pointers * al_p);
void printDistance(struct al_pointers * al_p);

#endif
