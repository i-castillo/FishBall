/* loop.c */
#include "runner.h"

void loop(struct al_pointers * al_p, struct Game * g){
  int numBases = 4;
  int numRunners = 4;
  int numCatchers = 4;
  int collisionRadius = 30;

  int imageWidth;
  int imageHeight;
  /* Initialize the objects */
  struct Player player;
  struct Ball ball;
  struct Runner runners[numRunners]; 
  struct Base bases[numBases];
  struct Catcher catchers[numCatchers];
  struct Catcher * catcher;

  initPlayer(&player);
  initBall(&ball);
  initRunners(runners, numRunners);
  initBases(bases, numBases);
  initCatchers(catchers, numCatchers);
  randomizeCatchers(catchers, numCatchers, collisionRadius);

  int done = 0;
  ALLEGRO_EVENT ev;
  int redraw;
  int balls = 8;
  int hits = 0;
  int power = 0;
  int randomed;
  int points;
  int score;
  int stage = 3;
  int ballcaught = 0;
  int released = 1;
  int begin = 0;
  ALLEGRO_BITMAP * background = al_load_bitmap("background.png");
  ALLEGRO_TIMER * powerTimer = al_create_timer(0.25);
  al_set_timer_count(powerTimer, 0);
  ALLEGRO_TIMER * waitTimer = al_create_timer(0.20);
  ALLEGRO_BITMAP * img_speed = al_load_bitmap("speed.png");
  ALLEGRO_SAMPLE * hitSound = al_load_sample("hit.wav");
  ALLEGRO_SAMPLE * powerSound = al_load_sample ("power.wav");

  al_reserve_samples(1);
  int SPEED[] = {5, 7, 4, 6, 8, 4, 3, 5, 9};

  if(g->difficulty != 1){
    updateDifficulty(g, SPEED, 9);    
  }
  //int SPEED[] = {2, 2, 2, 2,  2, 2, 2, 2, 2};
  while(!done)
  {
    if(player.power > 10){
      fprintf(stderr, "wtf is going on\n");
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
          power = al_get_timer_count(powerTimer); 
          al_set_timer_count(powerTimer, 1);

          if(power > 2){
            released = 1;
          }
          if(stage == 0 ){

            setPower(&player, -power);
            setSpeed(&player, -6 * power);
            setAlive(&player, 0);
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
          printRunners(runners, numRunners);
          break;
        case ALLEGRO_KEY_K: 
          printBases(bases, numBases);
          break;
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
      if(points > 0){
        hits++;
        al_play_sample(hitSound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
        loadBase(bases, numBases, runners, numRunners, hits, 5, points);

        stage = 1;

      }
      if(points == -1){ //no hit.
        hits++;
        stage = 1;
      }
      if(points == -2){
        hits++;
        al_play_sample(hitSound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
        stage = 1;
      }
    }

    else if(stage == 1){
      checkScore(runners, numRunners, &score);
      score += points;
      points = 0;
      ballcaught = catchBall(catchers, numCatchers, &ball, 30);
      if(ballcaught == 1){ // 1 means catcher caught
        stage = 2; 
        removeRunners(runners, numRunners);
        clearBases(bases, numBases);
        al_play_sample(powerSound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);

        /* Remove players from the field */
        randomizeCatchers(catchers, numCatchers, collisionRadius);
        al_start_timer(waitTimer);
        al_set_timer_count(waitTimer, 0);
      }
      else if(ballcaught == 2){ // 2 means ball wasn't caught.

        stage = 2;  
        randomizeCatchers(catchers, numCatchers, collisionRadius);        
        al_start_timer(waitTimer);
        al_set_timer_count(waitTimer, 0);
      }

    }

    else if(stage == 2 && stillRunning(runners, numRunners) == 0){

      if(al_get_timer_count(waitTimer) > 2){

        if(balls <= 0){
          done = 1;
        }

        al_stop_timer(waitTimer);
        al_set_timer_count(waitTimer, 0);
        balls--;
        released = 0;
        resetPlayer(&player);

        throwBall(&ball, SPEED[hits]);
        stage = 0;

      }
    }

    else if(stage == 3){
      if(begin == 1){
        al_start_timer(waitTimer);
        al_set_timer_count(waitTimer, 0);

        stage = 2;
      }
    }

    moveBall(&ball);
    if(al_get_timer_count(al_p->timer) % 120 == 0){
      moveCatchers(catchers, numCatchers, 4);
    }
    movePlayer(&player);
    moveRunners(runners, numRunners);

    if(redraw == 1 && al_is_event_queue_empty(al_p->event_queue)){
      redraw = 0;
      drawBackground(background);
      drawBases(bases, numBases);
      drawSpeed(img_speed, al_p, SPEED[hits]);
      //    drawPointVector(&player, &ball);
      drawCatchers(catchers, numCatchers);
      // drawCatcherswithPos(al_p->score, catchers);
      drawPowerBar(player.power);
      drawBalls(balls);
      drawScore(al_p, player.score);
      drawBall(&ball);
      drawPlayer(&player);
      drawRunners(runners, numRunners);
      //drawAngle();

      //printDistance(al_p);

      al_flip_display();
      al_clear_to_color(al_map_rgb(0,0,0));

    }

  } 




}
