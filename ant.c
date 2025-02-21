#include "ant.h"
#include "grid.h"
#include <stdio.h>

int position_valid(int x, int y, int rows, int columns) {
   return (x >= 0 && x < columns && y >= 0 && y < rows);
}

void turn(struct cell** grid, struct ant* ant) {
   
   int x = ant->x;
   int y = ant->y;
   char rule = grid[y][x].rule; 
  
   //turn right 
   if (rule == 'R' || rule == 'r') {
      ant->direction = (ant->direction + 1) % 4;
      return;
   }
   
   //turn left
   ant->direction = (ant->direction - 1 + 4) % 4;

}

void move(struct ant* ant, int rows, int columns, int* grid_end) {

   int next_x = ant->x;
   int next_y = ant->y;   

   switch(ant->direction) {            
      case north: 
         next_y--;
	 break;

      case east:
         next_x++;
	 break;

      case south:
	 next_y++;
	 break;

      case west:
	 next_x--;
	 break;
   }

   if  (!position_valid(next_x, next_y, rows, columns)) {
      *grid_end = 1;
      return;
   }

   ant->x = next_x;
   ant->y = next_y;

}

void update_grid(SDL_Surface* surface, struct cell** grid, struct ant* ant, Uint32* colors, 
		 char* rules, int n_rules, int rows, int columns, int* grid_end) {

   int ant_x = ant->x;
   int ant_y = ant->y;
   
   int rule_index = grid[ant_y][ant_x].r_index;
   int next_index = (rule_index + 1) % n_rules;
   grid[ant_y][ant_x].r_index = next_index;

   int color = colors[next_index];
   int rule = rules[next_index];
   grid[ant_y][ant_x].color = color;
   grid[ant_y][ant_x].rule = rule; 

   paint_cell(surface, ant_x, ant_y, color);
   turn(grid, ant);
   move(ant, rows, columns, grid_end);
   
}
