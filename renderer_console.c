#include <stdio.h>
#include "renderer.h"

void renderGrid(Cell grid[GRID_HEIGHT][GRID_WIDTH]) {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            switch (grid[y][x].state) {
                case DEAD: printf("-"); break;
                case ALIVE: printf("+"); break;
                case NEWBORN: printf("0"); break;
            }
        }
        printf("\n");
    }
}

void destroyRenderer() {
}
