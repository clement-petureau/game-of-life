#include <stdlib.h>
#include <time.h>
#include "game.h"

void initializeGrid(Cell grid[GRID_HEIGHT][GRID_WIDTH], float p) {
    srand((unsigned int)time(NULL));
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            grid[y][x].state = (rand() / (float)RAND_MAX) < p ? NEWBORN : DEAD;
        }
    }
}

int countAliveNeighbors(Cell grid[GRID_HEIGHT][GRID_WIDTH], int x, int y) {
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < GRID_WIDTH && ny < GRID_HEIGHT) {
                if (grid[ny][nx].state == ALIVE || grid[ny][nx].state == NEWBORN) {
                    count++;
                }
            }
        }
    }
    return count;
}

void updateGrid(Cell grid[GRID_HEIGHT][GRID_WIDTH]) {
    Cell newGrid[GRID_HEIGHT][GRID_WIDTH];

    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            int aliveNeighbors = countAliveNeighbors(grid, x, y);
            if (grid[y][x].state == ALIVE || grid[y][x].state == NEWBORN) {
                if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                    newGrid[y][x].state = DEAD;
                } else {
                    newGrid[y][x].state = ALIVE;
                }
            } else {
                if (aliveNeighbors == 3) {
                    newGrid[y][x].state = NEWBORN;
                } else {
                    newGrid[y][x].state = DEAD;
                }
            }
        }
    }

    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            grid[y][x] = newGrid[y][x];
        }
    }
}
