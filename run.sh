#!/bin/sh
echo "compiling runner..."
gcc -g main.c runner.h loop.c drawPlayer.c entities.h \
entities.h game.c drawBall.c throw.c drawRunner.c drawField.c debug.c screen.c \
-lm `pkg-config --libs allegro-5.0 \
allegro_primitives-5.0 allegro_ttf-5.0 allegro_font-5.0`


echo "finished compiling.."
