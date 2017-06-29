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
  int balls = 16;
  int hits = 0;
  int power = 0;

  ALLEGRO_TIMER * powerTimer = al_create_timer(0.25);
  while(!done)
  {
    if(balls <= 0){
      done = 1;
    }
    power = al_get_timer_count(powerTimer);
    setPower(&player, power);
    
    //move entities
    if(moveBall(&ball)){
      resetPlayer(&player);
    };
   movePlayer(&player);
    moveRunners(runners);
    al_wait_for_event(al_p->event_queue, &ev);
    if(ev.type == ALLEGRO_EVENT_TIMER){
      redraw = 1;

    }

    else if(ev.type == ALLEGRO_EVENT_KEY_UP){


      switch(ev.keyboard.keycode){
  /*      case ALLEGRO_KEY_W:
          player.y-= 6;
          break;
        
        case ALLEGRO_KEY_S:
          player.y+= 3;
          break; */
          
        case ALLEGRO_KEY_SPACE:

          al_stop_timer(powerTimer);
          setPower(&player, -power);
          setSpeed(&player, -6 * power);
          setAlive(&player, 0);
          break;
      }
    }      


    if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
      switch(ev.keyboard.keycode){
        case ALLEGRO_KEY_UP:
          throwBall(&ball);
          break;
        case ALLEGRO_KEY_K:
          printBases(bases);
          break;

        case ALLEGRO_KEY_SPACE:

          if(ball.alive == 1){
          al_set_timer_count(powerTimer, 1);
            
          al_start_timer(powerTimer);
      
          setAlive(&player, 1);
          setSpeed(&player, 3);


          }

          break;
      }

    }


    int points = hitBall(&player, &ball);
    if(points != 0){
      loadBase(bases, runners, hits, points);
      hits++;
      balls--;

    } 

    if(redraw == 1 && al_is_event_queue_empty(al_p->event_queue)){
      redraw = 0;
        printDistance(al_p);
    //  drawPointVector(&player, &ball);
      drawPowerBar(player.power);
      drawBalls(balls);
      drawScore(al_p, player.score);
      drawBall(&ball);
      drawPlayer(&player);
      drawRunners(runners);
      drawField(bases);
      al_flip_display();
     al_clear_to_color(al_map_rgb(0,0,0));


    }

  } 




}
