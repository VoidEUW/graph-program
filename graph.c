#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

/*
    the main function handling the program
*/
int main(int argc, char ** argv) {

    Grid grid;
    LinearFunction func1 = {1, 0, LINEAR_FUNCTION};

    fillBoard(grid);

    drawGraph(grid, func1);

    printBoard(grid);

    return 0;
}

/*
    filling the board content with either " " or "#"
    - filling with " " if its not a grid
    - filling with "#" if its a grid 
*/
void fillBoard(Grid grid) {
    for(int canvasY = 0; canvasY < HEIGHT; canvasY++) {
        for(int canvasX = 0; canvasX < LENGTH; canvasX++) {
            if(canvasY == HEIGHT/2) {
                for(int canvasX = 0; canvasX < LENGTH; canvasX++) {
                    grid[canvasX][canvasY] = '#';
                }
            } else {
                if(canvasX == LENGTH/2) {
                grid[canvasX][canvasY] = '#';
                }
                else grid[canvasX][canvasY] = ' ';
            }
        }
    }
}

/*
    filling the board content with either " " or "#"
    - filling with "*" on the right  
*/
void drawGraph(Grid grid, LinearFunction func) {
    for(int canvasX = 0; canvasX < LENGTH ;canvasX++) {
        int y = getPosY(canvasX, func);
        printf("X: %d  Y: %d\n", canvasX , y);
        if(y > 0) {
            grid[canvasX][y] = '*';
            printf("GRID[%d][%d]: %c\n", canvasX, y, grid[canvasX][y]);
        }
    }
}

int getPosY(int x, LinearFunction func) {
    FuncType funcType = func.FuncType;
    int y = 0;
    x = x - LENGTH/2;
    switch(funcType) {
        case LINEAR_FUNCTION:
            y = func.factor * x + func.yShift;
            break;
        default:
            printf("WRONG FUNCTIONTYPE!\nSTOPPING...\n");
            exit(EXIT_FAILURE);
            break;
    }
    return y;
}

/*
    printing the board content
    - type of content in grid[x][y]: char
*/
void printBoard(Grid grid) {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < LENGTH; x++) {
            printf("%c", grid[x][y]);
        }
        printf("\n");
    }
}