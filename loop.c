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
  int points;
  int stage = 3;
  int ballcaught = 0;
  int released;
  int begin = 0;
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
          if(stage == 0){
          /* Release bat */
          al_stop_timer(powerTimer);
          setPower(&player, -power);
          setSpeed(&player, -6 * power);
          setAlive(&player, 0);
          released = 1;
          break;

          }
      }
    }      

    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
      switch(ev.keyboard.keycode){
        case ALLEGRO_KEY_DOWN:
          begin = 1;
          break;
        case ALLEGRO_KEY_UP:
        case ALLEGRO_KEY_K: 
        case ALLEGRO_KEY_SPACE:
          if(stage == 0 && released == 0){
          /* Start bat */
          al_set_timer_count(powerTimer, 1);
          al_start_timer(powerTimer);
          setAlive(&player, 1);
          setSpeed(&player, 3);

          }
           break;
          
      }
    }

    if(stage == 0){
      power = al_get_timer_count(powerTimer); 
      setPower(&player, power);
      points = hitBall(&player, &ball);
      if(points != 0){

        loadBase(bases, runners, hits, points);
        stage = 1;

      }
    }

    else if(stage == 1){
      ballcaught = catchBall(catchers, &ball);
      if(ballcaught == 1){
        stage = 2; 
        removeRunners(runners);
        clearBases(bases);
        /* Remove players from the field */
      }
      else if(ballcaught == 2){

        stage = 2;            
      }

    }

    else if(stage == 2 && stillrunning(catchers) == 0){
      hits++;
      balls--;
      released = 0;
      resetPlayer(&player);
      throwBall(&ball);
      stage = 0;

    }

    else if(stage == 3){
      if(begin == 1){
        stage = 2;
      }
    }
      
    moveBall(&ball);
    moveCatchers(catcher);
    movePlayer(&player);
    moveRunners(runners);

    if(redraw == 1 && al_is_event_queue_empty(al_p->event_queue)){
      redraw = 0;
      drawPointVector(&player, &ball);
      drawCatcherswithPos(al_p->score, catchers);
      drawPowerBar(player.power);
      drawBalls(balls);
      drawScore(al_p, player.score);
      drawBall(&ball);
      drawPlayer(&player);
      drawRunners(runners);
      drawField(bases);
      //printDistance(al_p);

      al_flip_display();
      al_clear_to_color(al_map_rgb(0,0,0));

    }

  } 




}
