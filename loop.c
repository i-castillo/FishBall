/* loop.c */
#include "runner.h"

int loop(struct al_pointers * al_p){

  struct Player player;
  struct Ball ball;
  initPlayer(&player);
  initBall(&ball);

  int done = 0;
	while(!done)
	{
    drawBall(&ball);
    drawPlayer(&player);
		ALLEGRO_EVENT ev;
		al_wait_for_event(al_p->event_queue, &ev);


		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	} 


  

}
