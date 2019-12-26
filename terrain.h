#ifndef _TERRAIN_H_
#define _TERRAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>


#define SCREEN_WIDTH 1260
#define SCREEN_HEIGHT 720

typedef struct SDL_Instance
{
	SDL_Window *Window;
	SDL_Renderer *renderer;
} SDL_Instance;


int init_instance(SDL_Instance *);
void draw_stuff(SDL_Instance instance);
void quitSDL(SDL_Instance *);
int event_handler(void);
float **initGrid(char *filename);
float **girdAllocate(int width, int height);
void freeGrid(float **grid, int height);
unsigned int getSizeFromLine(char *str);
void draw_grid(SDL_Instance instance, float **grid);


#endif
