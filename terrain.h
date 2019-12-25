#ifndef _TERRAIN_H_
#define _TERRAIN_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct SDL_Instance
{
	SDL_Window *Window;
	SDL_Renderer *renderer;
} SDL_Instance;


int init_instance(SDL_Instance *);
void draw_stuff(SDL_Instance instance);
void quitSDL(SDL_Instance *);

#endif
