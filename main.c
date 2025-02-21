#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <string.h>
#include "constants.h"
#include "grid.h"
#include "ant.h"

int main (int argc, char *argv[]) {

   SDL_Init(SDL_INIT_VIDEO);

   SDL_Window* window = SDL_CreateWindow("Langton's Ant", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		                          SCREEN_WIDTH, SCREEN_HEIGHT, 0);   
   
   SDL_Surface* surface = SDL_GetWindowSurface(window);
  
   int rows = SCREEN_HEIGHT / CELL_SIZE;
   int columns = SCREEN_WIDTH / CELL_SIZE;



   Uint32 colors[16] = {COLOR_01, COLOR_02, COLOR_03, COLOR_04, COLOR_05, COLOR_06, COLOR_07, COLOR_08,
		        COLOR_09, COLOR_10, COLOR_11, COLOR_12, COLOR_13, COLOR_14, COLOR_15, COLOR_16}; 
     
   int n_rules;
   char* rules;

   //set rules
   if (argc > 1) {
      n_rules = strlen(argv[1]);
      rules = malloc((n_rules + 1) * sizeof(char));
      strcpy(rules, argv[1]);
   } else {
      n_rules = 2;
      rules = malloc((n_rules + 1) * sizeof(char));
      strcpy(rules, "LR");
   }

   struct cell** grid = create_grid(rows, columns, colors, rules);
   struct ant ant = (struct ant) {north, (columns - 1) / 2, (rows - 1) / 2}; 

   
   int running = 1;
   int paused = 0;
   int grid_end = 0;

   while (running) {
      SDL_Event event;
      while (SDL_PollEvent(&event)) {
         if (event.type == SDL_QUIT) 
     	    running = 0;
	    
	 if (event.type == SDL_KEYDOWN) {
	    switch (event.key.keysym.sym) {
	       case SDLK_SPACE:
	          paused = !paused;
	          break; 
            
	       case SDLK_ESCAPE:
	          running = 0;
		  break;

	    }
	 }
      }	 
      
      if (!paused && !grid_end) {
         update_grid(surface, grid, &ant, colors, rules, n_rules, rows, columns, &grid_end);
         SDL_UpdateWindowSurface(window);
      }
        
         
   }        
   

   free_grid(grid, rows);
   free(rules);
   SDL_DestroyWindow(window);
   SDL_Quit();

}

