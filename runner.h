/* runner.h */

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdlib.h>
#include <stdio.h>
#include "entities.h"
#include "images.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 800
#define FPS 60
#define PLAYER 0
#define BALL 1
#define HALF 2
#define QUARTER 4
#define HALF_SCREEN_WIDTH SCREEN_WIDTH / 2
#define EIGHTH_SCREEN_WIDTH SCREEN_WIDTH /8
#define QUARTER_SCREEN_HEIGHT SCREEN_HEIGHT / 4
#define THREE_QUARTER 0.75
#define ONE_TWENTIETH 0.05
#define PIVOT_X       0.25 * SCREEN_WIDTH
#define PIVOT_Y       0.75 * SCREEN_HEIGHT
#define EXTRA_BAT ONE_TWENTIETH * SCREEN_WIDTH
#define INIT_PLAYER_X SCREEN_WIDTH / HALF + EXTRA_BAT
#define INIT_PLAYER_Y PIVOT_Y
#define OFFSET_LENGTH SCREEN_WIDTH / QUARTER
#define PLAYER_LENGTH INIT_PLAYER_X - PIVOT_X






