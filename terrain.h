#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>

#ifndef _WIN_WIDTH_
#define WIN_WIDTH 720
#endif

#ifndef _WIN_HEIGHT_
#define WIN_HEIGHT 560
#endif

#ifndef _INCL_
#define INCL 0.7
#endif

unsigned int size;
/**
 * struct SDL_Instance - Defines a SDL Instance
 * @Window: SDL Window
 * @renderer: SDL Renderer
 */
typedef struct SDL_Instance
{
	SDL_Window *Window;
	SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *);
void quitSDL(SDL_Instance *);
int event_handler(void);
float **initGrid(char *filename);
float **girdAllocate(int width, int height);
void freeGrid(float **grid, int height);
unsigned int getSizeFromLine(char *str);
void draw_grid(SDL_Instance instance, float **grid);

#endif
