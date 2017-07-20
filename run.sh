#!/bin/sh
echo "compiling runner..."
gcc -g main.c runner.h loop.c player.c entities.h \
entities.h game.c ball.c throw.c runner.c \
catchers.c debug.c screen.c run.c bases.c catch.c gameUtils.c images.h \
-lm `pkg-config --libs allegro-5.0 \
allegro_primitives-5.0 allegro_ttf-5.0 allegro_font-5.0 allegro_image-5.0 \
allegro_audio-5.0 allegro_acodec-5.0`


echo "finished compiling.."
