/* main.c */
#include "runner.h"

int main(void)
{
  /* Initialize allegro pointers */
	int width = SCREEN_WIDTH;
	int height = SCREEN_HEIGHT;

  struct al_pointers * pointers = malloc(sizeof(struct al_pointers));
  if(!init_game(pointers, width, height))
    return EXIT_FAILURE;
  
    srand(time(NULL));
    loop(pointers);
    destroy_allegro(pointers);

					//destroy our display object

	return 0;
}
