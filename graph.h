#ifndef GRAPH_H
#define GRAPH_H

#define LENGTH 100
#define HEIGHT 25

typedef enum FuncType{
    LINEAR_FUNCTION
} FuncType;

typedef struct LinearFunction {
    int factor;
    int yShift;
    FuncType FuncType;
} LinearFunction;

typedef char Grid[LENGTH][HEIGHT];

void fillBoard(Grid grid);
void drawGraph(Grid grid, LinearFunction func);
int getPosY(int posX, LinearFunction func);
void printBoard(Grid grid);

#endif