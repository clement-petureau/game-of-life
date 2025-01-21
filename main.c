#include <stdio.h>
#include <stdbool.h>
#include <string.h> // Pour strcmp
#include "game.h"
#include "renderer.h"

#ifdef USE_CSFML
#include "renderer_csfml.c"
#else
#include "renderer_console.c"
#endif

void sleepMilliseconds(int ms) {
#ifdef USE_CSFML
    sfSleep((sfTime){ms * 1000});
#else
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000;
    nanosleep(&ts, NULL);
#endif
}

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
            sleepMilliseconds(200); // Ralentir la simulation
        } else {
            printf("Appuyez sur Entrée pour continuer...\n");
            getchar(); // Attendre une entrée utilisateur en mode console
        }
    }

    destroyRenderer();
    return 0;
}
