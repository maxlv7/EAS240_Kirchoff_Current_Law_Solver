#include "EAS240_PP1_functions.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int nob, non;
    char filename[128];
    FILE *fp = NULL;

    scanf("%s", filename);
    fp = fopen(filename, "r");

    if (!fp)
    {
        puts("no such file!\n");
        exit(0);
    }
    fscanf(fp, "%d", &nob);
    fscanf(fp, "%d", &non);
    Branch *pb = (Branch *)malloc(sizeof(Branch) * nob);
    double *voltages = (double *)malloc(sizeof(double) * non);
    for (int i = 0; i < nob; i++)
    {
        fscanf(fp, "%d %lf %d %d", &((pb + i)->type), &((pb + i)->value), &((pb + i)->startNode), &((pb + i)->endNode));
    }
    fclose(fp);
    SolveCircuit(pb, voltages, nob, non);
    PrintCircuit(filename, pb, voltages, nob, non);

    free(pb);
    free(voltages);
    return 0;
}