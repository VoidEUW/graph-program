#ifndef GRAPH_H
#define GRAPH_H

#define LENGTH 100
#define HEIGHT 30

#define X_AXIS_LINE '-'
#define Y_AXIS_LINE '|'
#define COORDINATE_START 'O'

typedef enum FuncType{
    LINEAR_FUNCTION,
    POWER_FUNCTION
} FuncType;

typedef struct Function {
    double factor;
    int power;
    double yShift;
    FuncType FuncType;
} Function;

typedef char Grid[LENGTH][HEIGHT];

void fillBoard(Grid grid);
void drawGraph(Grid grid, Function func, char linetype);
int getPosY(int posX, Function func);
void printBoard(Grid grid);

#endif