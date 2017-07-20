/* main.c */
#include "runner.h"

int main(void)
{
  /* Initialize allegro pointers */
	int width = SCREEN_WIDTH;
	int height = SCREEN_HEIGHT;

  struct al_pointers * pointers = malloc(sizeof(struct al_pointers));
  if(!init_game(pointers, width, height)){
    free(pointers);
    return EXIT_FAILURE;
  }
  
    int done = 0;
    srand(time(NULL));
    struct Game g = {1, 0, 1};
    loadStart(pointers, &g);
    while(done == 0){
      loop(pointers, &g);
      loadGameOver(pointers, &done);

    }
    destroy_allegro(pointers);



	return 0;
}
