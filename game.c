/* game.c */
#include "runner.h"

int init_game( struct al_pointers * al_p, int width, int height){

	if(!al_init())									
		return 0;

  al_init_font_addon();
	al_init_ttf_addon();
  al_init_primitives_addon();
  
  al_p->display = al_create_display(width, height);
  al_p->score =	al_load_font("GFSDidot.otf", 18, 0);
	al_p->timer = al_create_timer(1.0 / FPS);
  al_p->event_queue = al_create_event_queue();

  if(!al_p->display || !al_p->score || !al_p->timer || !al_p->event_queue){

    destroy_allegro(al_p);
    return 0;

  }

  
	al_register_event_source(al_p->event_queue, 
      al_get_timer_event_source(al_p->timer));

	al_start_timer(al_p->timer);
  
 return 1;

}

int destroy_allegro( struct al_pointers * al_p){
  	al_destroy_event_queue(al_p->event_queue);
	al_destroy_timer(al_p->timer);
	al_destroy_display(al_p->display);	

  free(al_p);
};


