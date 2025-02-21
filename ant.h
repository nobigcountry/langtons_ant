#ifndef ANT_H
#define ANT_H

#include <SDL2/SDL.h>
#include "constants.h"
#include "grid.h"

enum Direction {
   north,  // 0
   east,   // 1
   south,  // 2
   west,   // 3
};

struct ant {
   enum Direction direction;
   int x;
   int y;
};

int position_valid(int x, int y, int rows, int columns);

void turn(struct cell** grid, struct ant* ant);

void move(struct ant* ant, int rows, int columns, int* grid_end);

void update_grid(SDL_Surface* surface, struct cell** grid, struct ant* ant, Uint32* colors, 
		 char* rules, int n_rules, int rows, int columns, int* grid_end);

#endif


