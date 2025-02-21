#ifndef GRID_H
#define GRID_H

#include <SDL2/SDL.h>
#include "constants.h"

struct cell {
   Uint32 color;
   char rule;
   int r_index;

};

struct cell** create_grid(int rows, int columns, Uint32* colors, char* rules);

void free_grid(struct cell** grid, int rows);

void paint_cell(SDL_Surface* surface, int x, int y, Uint32 color);

#endif 


