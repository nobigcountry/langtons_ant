# Langton's Ant Simulation
[Langton's Ant](https://en.wikipedia.org/wiki/Langton%27s_ant) is a cellular automaton and a two-dimensional Turing machine. This project is a simple implementation using the SDL2 library.

By default, the program creates a 1600x900 window for the simulation, with each cell of the grid having a size of 4x4 pixels. These parameters, along with the colors for each cell state, can be  modified in the `constants.h` header file.

## Compilation and Running the Program
Simply run `make` to compile and `make clean` to clean up the directory. Make sure you have [SDL2](https://wiki.libsdl.org/SDL2/Installation) installed.

You can run the default two-state simulation using:
```bash
./langton
```
To define custom rules for each state, pass a sequence of `L`(Left) or `R`(RIGHT) as an argument. For example:
```bash
./langton LLRLLLRRL
or
./langton llrlllrrl
```
There are up to 16 different states by default, but this can easily be changed in the **colors[16]** vector in the `main.c` file.

During the simulation you can use:  
`SPACEBAR`: to pause/unpause the simulation.  
`ESC`: to exit the program.
