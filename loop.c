/* loop.c */
#include "runner.h"

int loop(struct al_pointers * al_p){
  /* lazy */
  al_install_keyboard();
  al_register_event_source(al_p->event_queue, al_get_keyboard_event_source());

  struct Player player;
  struct Ball ball;
  struct Runner runners[4]; 
  struct Base bases[4];
  initPlayer(&player);
  initBall(&ball);
  initRunners(runners);
  initBases(bases);


  int done = 0;
  ALLEGRO_EVENT ev;
  int redraw;
  int hit = 1;
  while(!done)
  {
    //draw entities


    //move entities
    moveBall(&ball);
    movePlayer(&player);
    moveRunners(runners);
    al_wait_for_event(al_p->event_queue, &ev);
    if(ev.type == ALLEGRO_EVENT_TIMER){
      redraw = 1;

    }

    else if(ev.type == ALLEGRO_EVENT_KEY_UP){
      switch(ev.keyboard.keycode){
        case ALLEGRO_KEY_UP:
          throwBall(&ball);
          break;
        case ALLEGRO_KEY_SPACE:
          break;
      }
    }      


    if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
      switch(ev.keyboard.keycode){
        case ALLEGRO_KEY_K:
          printBases(bases);
          break;

        case ALLEGRO_KEY_SPACE:
          break;
      }


    };


    if(hitBall(&player, &ball)){
      loadBase(bases, runners, hit, 1); 
      hit++;

    } 

    if(redraw == 1 && al_is_event_queue_empty(al_p->event_queue)){
      redraw = 0;
      //  printDistance(al_p);
      drawBall(&ball);
      drawPlayer(&player);
      drawRunners(runners);
      drawField(bases);
      al_flip_display();
      al_clear_to_color(al_map_rgb(0,0,0));


    }

  } 




}
