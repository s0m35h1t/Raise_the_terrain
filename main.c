#include "terrain.h"

int main(void)
{
	SDL_Instance instance;

	if (init_instance(&instance) != 0)
		return (1);

	while (1)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		draw_stuff(instance);
		SDL_RenderPresent(instance.renderer);
	}
	quitSDL(&instance);

	return (0);
}
