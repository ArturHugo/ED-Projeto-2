#include "graph.h"

Graph ReadGraph(char* Filename){
    int numVertices;                // Number of vertices/nodes in the graph.
    int currentIndex;               // Index of the current node in the adjacency matrix.
    int targetIndex;                // Index of the target node of an edge.
    float edgeWeight;               // Weight of an edge (element of the matrix).
    Graph AdjVector;                // Our graph will is a vector of adjacency matrixes. 
    
    FILE* f = fopen(Filename, "r");
    if(f==NULL){
        printf("ReadGraph exit with 1: nonexisting input file.");
        exit(1);
    }
    
    // Reads the number of vertices and alocate our gaph (adjacency vector).
    fscanf(f, "%d\n", &numVertices);
    AdjVector = (Graph)malloc(numVertices*sizeof(List*))

    // Since the adjacency matriz is simetric, we just need to read the elements above 
    //the main diagonal. (at the moment, the function is reading every element)
    for(currentIndex = 0; currentIndex < numVertices; currentIndex++){
        
        targetIndex = 0;    // Index of the node given edge leads to.

        // Each line index corresponds to a node in our graph.
        // The loop below reads each weight of given line and
        //adds it to its current node adjacency list if it's non zero.
        while(fscanf("%f, ", &aux) != '\n'){
            if(edgeWeight != 0){
                AddToList(AdjVector[currentIndex], targetIndex, edgeWeight);
            }

            // Once the edge is added or not, the next one will be read,
            //so the index of target node is incremented.
            targetIndex++;
        }
    }
}