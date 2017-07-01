/* loop.c */
#include "runner.h"

int loop(struct al_pointers * al_p){

  al_install_keyboard();
  al_register_event_source(al_p->event_queue, al_get_keyboard_event_source());

  /* Initialize the objects */
  struct Player player;
  struct Ball ball;
  struct Runner runners[4]; 
  struct Base bases[4];
  struct Catcher catchers[4];
  struct Catcher * catcher;


  initPlayer(&player);
  initBall(&ball);
  initRunners(runners);
  initBases(bases);
  initCatchers(catchers);
  randomizeCatchers(catchers);

  int done = 0;
  ALLEGRO_EVENT ev;
  int redraw;
  int balls = 16;
  int hits = 0;
  int power = 0;
  int randomed;

  ALLEGRO_TIMER * powerTimer = al_create_timer(0.25);
  al_set_timer_count(powerTimer, 0);
  while(!done)
  {
    if(balls <= 0){
      done = 1;
    }

    al_wait_for_event(al_p->event_queue, &ev);
    if(ev.type == ALLEGRO_EVENT_TIMER){
      redraw = 1;

    }

    else if(ev.type == ALLEGRO_EVENT_KEY_UP){


      switch(ev.keyboard.keycode){

        case ALLEGRO_KEY_SPACE:
          /* Release bat */
          al_stop_timer(powerTimer);
          setPower(&player, -power);
          setSpeed(&player, -6 * power);
          setAlive(&player, 0);
          break;
      }
    }      


    if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
      switch(ev.keyboard.keycode){
        case ALLEGRO_KEY_DOWN:
          if(catcher)
     //     fprintf(stderr, "b->x: %f b->y: %f c->x: %f c->y: %f b->angle %f \n",
     //         ball.x, ball.y, catcher->x, catcher->y, ball.angle);
        case ALLEGRO_KEY_UP:
          randomed = 0;
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
      
      catcher = checkIfCatch(catchers, &ball);
      if(catcher == NULL){
        loadBase(bases, runners, hits, points);
      }

      hits++;
      balls--;


    }
    power = al_get_timer_count(powerTimer);



    setPower(&player, power);
    if(moveBall(&ball)){
      if(randomed == 0){
     //   randomizeCatchers(catchers);
        randomed = 1;
        catcher = NULL;
      }
      resetPlayer(&player);
    }
    if(moveCatcher(catcher, &ball)){
         catcher = NULL;
    //     al_rest(3.0);
         ball.alive = 0;
      if(randomed == 0){
       // randomizeCatchers(catchers);
        randomed = 1;
      }
      //resetPlayer(&player);

    };
    movePlayer(&player);
    moveRunners(runners);


    if(redraw == 1 && al_is_event_queue_empty(al_p->event_queue)){
      redraw = 0;
      //  drawPointVector(&player, &ball);
      drawCatcherswithPos(al_p->score, catchers);
      drawPowerBar(player.power);
      drawBalls(balls);
      drawScore(al_p, player.score);
      drawBall(&ball);
      drawPlayer(&player);
      drawRunners(runners);
      drawField(bases);
      //   printDistance(al_p);

      al_flip_display();
      al_clear_to_color(al_map_rgb(0,0,0));


    }

  } 




}
