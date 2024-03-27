#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

/*
    the main function handling the program
*/
int main(int argc, char ** argv) {

    Grid grid;
    //Function func1 = {1, 0, 0, POWER_FUNCTION};
    Function func2 = {0.2, 3, 0, POWER_FUNCTION};

    fillBoard(grid);

    //drawGraph(grid, func1, '*');
    drawGraph(grid, func2, '$');

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
                    grid[canvasX][canvasY] = X_AXIS_LINE;
                }
            } else {
                if(canvasX == LENGTH/2) {
                grid[canvasX][canvasY] = Y_AXIS_LINE;
                }
                else grid[canvasX][canvasY] = ' ';
            }
        }
    }
    grid[LENGTH/2][HEIGHT/2] = COORDINATE_START;
}

/*
    filling the board content with either " " or "#"
    - filling with "*" on the right  
*/
void drawGraph(Grid grid, Function func, char linetype) {
    for(int canvasX = 0; canvasX < LENGTH ;canvasX++) {
        int y = getPosY(canvasX, func);
        if (((y + HEIGHT/2) >= 0) && ((y + HEIGHT/2) < HEIGHT) ) {
            grid[canvasX][y+HEIGHT/2] = linetype;
        } else continue;
    }
}

int getPosY(int x, Function func) {
    FuncType funcType = func.FuncType;
    int y = 0;
    int s = 0;
    x = x - LENGTH/2;
    switch(funcType) {
        case LINEAR_FUNCTION:
            y = -func.factor * x - func.yShift; // Values have to be inverted
            break;
        case POWER_FUNCTION:
            s = x;
            if(func.power > 0) {
                for(int i = 1; i < func.power; i++) s = s * x;
            }
            else s = 1;
            y = -func.factor * s - func.yShift; // Values have to be inverted
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