/* screen.c */
#include "runner.h"
void drawScore(struct al_pointers * al_p, int score){
  
    al_draw_textf(al_p->score, al_map_rgb(255,255,255), 200, 10, 0, "%i", score );
    
}
void drawBackground(ALLEGRO_BITMAP * image){
  al_draw_bitmap(image, 0, 0, 0);
}

void drawBalls(int ballsRem){
  int i;
  for(i = 0; i < ballsRem; i++){
    al_draw_filled_circle(20 * i + 10, 40, 5, al_map_rgb(100,225, 100));

  }

}
void drawSpeed(ALLEGRO_BITMAP * img, struct al_pointers * al_p, int speed){
  al_draw_bitmap(img, SCREEN_WIDTH/2 - 50, SCREEN_HEIGHT * 0.90, 0);
    al_draw_textf(al_p->score, al_map_rgb(255,255,255), SCREEN_WIDTH /2 + 50,
        SCREEN_HEIGHT * 0.90, 0, "%i", speed );

}

void drawPowerBar(int power){
  int i;
  for(i = 0; i < power; i++){
    al_draw_filled_rectangle(i * 50 + 10, 750, i * 50 + 60, 780, 
        al_map_rgb(i * 25, i * 25, 120));
  }

}

void loadStart(struct al_pointers * al_p, struct Game * g){
  int done = 0;
  ALLEGRO_EVENT ev;
  ALLEGRO_BITMAP * start = al_load_bitmap("start.png");
  al_draw_bitmap(start, 0, 0, 0);
  al_flip_display();
  
  while(!done){
      al_wait_for_event(al_p->event_queue, &ev);

      if(ev.type == ALLEGRO_EVENT_KEY_UP){
        switch(ev.keyboard.keycode){
          case ALLEGRO_KEY_S:
            loadSettings(al_p, g);
            break;
          case ALLEGRO_KEY_R:
            loadRules(al_p);
            break;
          case ALLEGRO_KEY_SPACE:
            done = 1;
            break;
        }
          al_draw_bitmap(start, 0, 0, 0);
          al_flip_display();

      }

  }

}

void loadSettings(struct al_pointers * al_p, struct Game * g){
  int done = 0;
  ALLEGRO_EVENT ev;
  ALLEGRO_BITMAP * start = al_load_bitmap("settings.png");
  ALLEGRO_FONT * f = al_load_ttf_font("GFSDidot.otf", 15, 0);
  al_draw_bitmap(start, 0, 0, 0);

  
  while(done == 0){
      al_wait_for_event(al_p->event_queue, &ev);

      if(ev.type == ALLEGRO_EVENT_KEY_UP){
        switch(ev.keyboard.keycode){
          case ALLEGRO_KEY_ESCAPE:
            return;
          case ALLEGRO_KEY_I:
            g->difficulty = g->difficulty++ % 3 + 1;
            break;
          case ALLEGRO_KEY_S:
            g->hasSound = !g->hasSound;
            break;
        }       
      }
      al_clear_to_color(al_map_rgb(0,0,0));
       al_draw_bitmap(start, 0, 0, 0);

      al_draw_textf(f, al_map_rgb(255,255,255), 200, 500, 0,
          "sound: %i difficulty: %i", g->hasSound, g->difficulty);
      al_flip_display();


  }

}

void loadRules(struct al_pointers * al_p){


}

void loadGameOver(struct al_pointers * al_p, int * finished){
  int done = 0;
  ALLEGRO_EVENT ev;
  ALLEGRO_BITMAP * start = al_load_bitmap("over.png");
  al_draw_bitmap(start, 0, 0, 0);
  al_flip_display();
  
  while(!done){
      al_wait_for_event(al_p->event_queue, &ev);


      if(ev.type == ALLEGRO_EVENT_KEY_UP){
        switch(ev.keyboard.keycode){
          case ALLEGRO_KEY_ESCAPE:
            *finished = 1;
            done = 1;
            break;
          case ALLEGRO_KEY_SPACE:
            done = 1;
            break;
        }
        
      }

  }


}
