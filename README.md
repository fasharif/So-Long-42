# So-Long-42
The goal is to create your own 2D game where you have a map that can have different dimensions and contents.

Requirements to run the game
Only tested on macOS Catalina (Version 10.15.7).
For all other OS it is not guaranteed to work.
OpenGL and AppKit is required to run it.
If you want to run it on Linux [here](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#compilation-on-linux) is a tutorial that might help and [here](https://github.com/42Paris/minilibx-linux) is the required version of miniLibX, this is not tested with my so_long.

Map
A valid map is structured as followed:

1 player (P)
at least 1 exit (E)
at least 1 collectible (C)`
is recatangular
has a solid outside border out of walls (1)
all the empty spaces are filled with 0
map has to be .ber
no other characters than:
P
E
C
1
0
i.e. map1.ber:

During the game
The player can only be moved by WASD.
The player can not move into walls.
The player can only exit if all collectibles are collected.
The amount of movements is counted and displayed in the terminal.
Every try to move even if it is invalid will be counted as one move.

All the visualization is done with the help of the MiniLibX library.
