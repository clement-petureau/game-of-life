#include <stdio.h>
#include <stdbool.h>
#include "game.h"
#include "renderer.h"

#ifdef USE_CSFML
#include "renderer_csfml.c"
#else
#include "renderer_console.c"
#endif

int main(int argc, char *argv[]) {
    bool useCSFML = false;
    if (argc > 1 && strcmp(argv[1], "csfml") == 0) {
        useCSFML = true;
    }

    Cell grid[GRID_HEIGHT][GRID_WIDTH];
    initializeGrid(grid, 0.3f);

    while (true) {
        renderGrid(grid);
        updateGrid(grid);

        if (useCSFML) {
            sfSleep((sfTime){200000}); 
        } else {
            getchar(); 
        }
    }

    destroyRenderer();
    return 0;
}
