#include "raylib.h"
#include <bits/stdc++.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int CELL_SIZE = 1;
const int GRID_SIZE =  800/ CELL_SIZE;
int FPS = 1;

// not const 
int grid[GRID_SIZE][GRID_SIZE];

#define EMPTY 0
#define ALIVE 1


void InitializeGrid() {

    // Set all cells to Empty
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            grid[i][j] = EMPTY;

    // make the top center cell alive 
    grid[GRID_SIZE / 2][0] = ALIVE;
    grid[(GRID_SIZE / 2)+1][0] = ALIVE;
    grid[(GRID_SIZE / 2)-1][0] = ALIVE;

}

void DrawTriangle () {

    /*
        all alive patterns 
            100
            011
            010 *
            001 *
 */


    for (int i=1; i<GRID_SIZE-1; i++)
        for (int j=1; j<GRID_SIZE; j++){
            if (!grid[i-1][j-1] && grid[i][j-1] && !grid[i+1][j-1])
                grid[i][j] = ALIVE;
            if (!grid[i-1][j-1] && !grid[i][j-1] && grid[i+1][j-1])
                grid[i][j] = ALIVE;
            if (grid[i-1][j-1] && !grid[i][j-1] && !grid[i+1][j-1])
                grid[i][j] = ALIVE;
            if (!grid[i-1][j-1] && grid[i][j-1] && grid[i+1][j-1])
                grid[i][j] = ALIVE;
        }
}



void DrawBox (int x, int y, int width, int height, int state) {

    auto color = CLITERAL(Color){ 0, 0, 0, 255 };

    if (state == ALIVE){
        // color = CLITERAL(Color){ 255, 255, 255, 255 };
        color = WHITE;
    }

    DrawRectangle(x, y, width, height, color);

}


int main() {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Conway's Game of Life");
    InitializeGrid();
    SetTargetFPS(FPS);

    DrawTriangle();

    while (!WindowShouldClose()) {

        // Setup the canvas
        BeginDrawing();
        ClearBackground(RAYWHITE);


        // Render the grid
        for (int i = 0; i < GRID_SIZE; i++)
            for (int j = 0; j < GRID_SIZE; j++)
                DrawBox (i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE, CELL_SIZE, grid[i][j]);

        // Update the grid
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
