#include "terrain.h"
/**
 * girdAllocate - creates a 2 dimensional array of floats initialized to 0
 * @width: width of array
 * @height: height of array
 * Return: a double pointer
 */
float **girdAllocate(int width, int height)
{
    int l, c;
    float **array;

    if (width <= 0 || height <= 0)
        return (NULL);
    array = (float **)malloc(sizeof(float *) * height);
    if (array == NULL)
        return (NULL);
    for (l = 0; l < height; l++)
    {
        array[l] = (float *)malloc(sizeof(float) * width);
        if (array[l] == NULL)
        {
            for (c = 0; c < l; c++)
                free(array[c]);
            free(array);
            return (NULL);
        }
        for (c = 0; c < width; c++)
            array[l][c] = 0;
    }
    return (array);
}

float **initGrid(char *filename)
{
    FILE *f = NULL;
    char *buffer = NULL, *elmValue;
    size_t buffBytes = 0;
    unsigned int size = 0, i = 0, j = 0;
    float **grid = NULL;

    f = fopen(filename, "r");
    while (getline(&buffer, &buffBytes, f) != -1)
    {
        j = 0;
        if (i == 0)
        {
            size = getSizeFromLine(buffer);
            grid = girdAllocate(size, size);
        }
        elmValue = strtok(buffer, " \n");
        while (elmValue)
        {
            grid[j][i] = strtof(elmValue, NULL);
            elmValue = strtok(NULL, " \n");
            j++;
        }
        free(buffer);
        buffer = NULL;
        i++;
    }
    return (grid);
}

/**
 * freeGrid - frees a 2D grid.
 * @grid: grid to free
 * @height: height of grid
 *
 * Return: void
 */
void freeGrid(float **grid, int height)
{
    int i;

    if (grid == NULL || height <= 0)
        return;
    for (i = 0; i < height; i++)
        free(grid[i]);
    free(grid);
}

/**
 *getSizeFromLine - splits a string according to the delimiter
 *@str: pointer to the string
 *@delim: pointer to the delimiter
 *Return: a number
 */
unsigned int size;

unsigned int getSizeFromLine(char *str)
{
	char *buffer, *strCpy = strdup(str);
	unsigned int words = 0;

	if (*str == NULL)
	{
		free(strCpy);
		return (-1);
	}
	buffer = strtok(strCpy, " \n");
	words += 1;
	while (buffer != NULL)
	{
		buffer = strtok(NULL, " \n");
		if (buffer != NULL)
			words += 1;
	}
	free(strCpy);
	size = words;
	return (words);
}

void draw_grid(SDL_Instance instance, float **z)
{
	extern unsigned int size;
	int res = size - 1;
	float inclination = 0.7;
	int width = SCREEN_WIDTH * 0.8;
	int height = SCREEN_HEIGHT  * 0.8;
	int x = 0, y = 0, dx = (width / res) - 1, dy = (height / res) - 1;
	int X = 0, Y = 0, Wx = 0, Wy = 0, xOffset = 270, yOffset = 150;
	int indx = 0, indy = 0;

	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	for (x = 0; x <= dx * res; x += dx)
	{
		indy = 0;
		for (y = 0; y < dy * res; y += dy)
		{
			X = (x * inclination) - (inclination * y) + xOffset;
			Y = y * (1 - inclination) + (1 - inclination) * x + yOffset - z[indx][indy];
			Wx = (x * inclination) - (inclination * (y + dy)) + xOffset;
			Wy = (1 - inclination) * x + (1 - inclination) * (y + dy) + yOffset - z[indx][indy + 1];
			SDL_RenderDrawLine(instance.renderer, X, Y, Wx, Wy);
			indy++;
		}
		indx++;
	}
 	indx = 0;
	indy = 0;
	for (y = 0; y <= dy * res; y += dy)
	{
		indx = 0;
		for (x = 0; x < dx * res; x += dx)
		{
			X = (x * inclination) - (inclination * y) + xOffset;
			Y = y * (1 - inclination) + x * (1 - inclination) + yOffset - z[indx][indy];
			Wx = (inclination * (x + dx)) - (inclination * y) + xOffset;
			Wy = (1 - inclination) * (x + dx) + (1 - inclination) * y + yOffset - z[indx + 1][indy];
			SDL_RenderDrawLine(instance.renderer, X, Y, Wx, Wy);
			indx++;
		}
		indy++;
	}
}