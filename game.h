#ifndef GAME_H
#define GAME_H

typedef enum { DEAD, ALIVE, NEWBORN } CellState;

typedef struct {
    CellState state;
} Cell;

#define GRID_WIDTH 80
#define GRID_HEIGHT 60

void initializeGrid(Cell grid[GRID_HEIGHT][GRID_WIDTH], float p);
int countAliveNeighbors(Cell grid[GRID_HEIGHT][GRID_WIDTH], int x, int y);
void updateGrid(Cell grid[GRID_HEIGHT][GRID_WIDTH]);

#endif
