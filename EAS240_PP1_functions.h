
#include <stdio.h>

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

typedef struct Branch_struct
{
    int type;     // 1 is source, 0 is resistor
    double value; // value for resistor or source
    int startNode;
    int endNode;
} Branch;

void PrintCircuit(char filename[], const Branch *circuit, double *voltages, int numBranches, int numNodes);
void SolveCircuit(const Branch *circuit, double *voltages, int numBranches, int numNodes);
void PerformGaussElimination(double *arr, int ROWS, int COLS);

#endif