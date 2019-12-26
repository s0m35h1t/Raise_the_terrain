#include "terrain.h"

int main(int argc, char *argv[])
{

	if (argv[1] == NULL)
		return (0);
	float **grid = initGrid(argv[1]);
	
	if (init_instance(&instance) != 0)
		return (1);
	while (1)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (event_handler() == 1)
		 	break;
		// draw_stuff(instance);
		draw_grid(instance, grid);
		SDL_RenderPresent(instance.renderer);
	}
	quitSDL(&instance);

	return (0);
}
