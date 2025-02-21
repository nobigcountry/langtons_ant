#include "grid.h"
#include <stdlib.h>
#include <stdio.h>

struct cell** create_grid(int rows, int columns, Uint32* colors, char* rules) {                       
   struct cell** grid = malloc(rows * sizeof(struct cell*));

   for (int i = 0; i < rows; i++) {
      grid[i] = malloc(columns * sizeof(struct cell));
      for (int j = 0; j < columns; j++) {
         grid[i][j] = (struct cell) {colors[0], rules[0], 0};
      }
   }

   return grid;
}

void free_grid(struct cell** grid, int rows) {
   
   for (int i = 0; i < rows; i++) 
      free(grid[i]);

   free(grid);
}

void paint_cell(SDL_Surface* surface, int x, int y, Uint32 color) {

   SDL_Rect rect = (SDL_Rect) {x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
   SDL_FillRect(surface, &rect, color);

}
