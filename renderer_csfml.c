#include <SFML/Graphics.h>
#include "renderer.h"

#define CELL_SIZE 10

static sfRenderWindow *window = NULL;

void initRenderer() {
    sfVideoMode mode = {GRID_WIDTH * CELL_SIZE, GRID_HEIGHT * CELL_SIZE, 32};
    window = sfRenderWindow_create(mode, "Game of Life", sfResize | sfClose, NULL);
}

void renderGrid(Cell grid[GRID_HEIGHT][GRID_WIDTH]) {
    if (!window) initRenderer();

    sfRenderWindow_clear(window, sfBlack);

    sfRectangleShape *cellShape = sfRectangleShape_create();
    sfRectangleShape_setSize(cellShape, (sfVector2f){CELL_SIZE, CELL_SIZE});

    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            sfVector2f position = {x * CELL_SIZE, y * CELL_SIZE};
            sfRectangleShape_setPosition(cellShape, position);

            if (grid[y][x].state == DEAD) {
                sfRectangleShape_setFillColor(cellShape, sfBlack);
            } else if (grid[y][x].state == ALIVE) {
                sfRectangleShape_setFillColor(cellShape, sfWhite);
            } else if (grid[y][x].state == NEWBORN) {
                sfRectangleShape_setFillColor(cellShape, sfGreen);
            }

            sfRenderWindow_drawRectangleShape(window, cellShape, NULL);
        }
    }

    sfRenderWindow_display(window);
    sfRectangleShape_destroy(cellShape);
}

void destroyRenderer() {
    if (window) {
        sfRenderWindow_destroy(window);
        window = NULL;
    }
}
