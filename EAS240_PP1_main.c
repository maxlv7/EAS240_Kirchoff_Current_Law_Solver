#include "EAS240_PP1_functions.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    int numBranches; //number of branches
    int numNodes; //number of node
    char filename[128];
    //Set the file as NULL
    FILE *fp = NULL;
    //Get file name 
    scanf("%s", filename);
    //Open the file
    fp = fopen(filename, "r");
    //check if the file exists
    if (!fp){
        puts("no such file!\n");
        return -1;
    }
    //Get the numbers of branches and nodes from files
    fscanf(fp, "%d", &numBranches);
    fscanf(fp, "%d", &numNodes);
    //Using dynamic memory allocation for branch elements
    Branch *circuit = (Branch *)malloc(sizeof(Branch) * numBranches);
    //Using dynamic memory allocation for voltages, and numVoltages = numNodes
    double *voltages = (double *)malloc(sizeof(double) * numNodes);
      //Get input from files
    for (int i = 0; i < numBranches; i++){
        fscanf(fp, "%d %lf %d %d", &((circuit + i)->type), &((circuit + i)->value), &((circuit + i)->startNode), &((circuit + i)->endNode));
    }
    //close the file
    fclose(fp);
    //Function Call
    SolveCircuit(circuit,voltages,numBranches,numNodes);
    PrintCircuit(filename, circuit, voltages, numBranches, numNodes);
    //Free memory
     free(circuit);
     free(voltages);
    return 0;
}
