#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

AdjVector ReadGraph(char* Filename){
    int numVertices;                // Number of vertices/nodes in the graph.
    int currentIndex;               // Index of the current node in the adjacency matrix.
    int targetIndex;                // Index of the target node of an edge.
    float edgeWeight;               // Weight of an edge (element of the matrix).
    AdjVector graph;                // Our graph will is a vector of adjacency matrixes. 
    
    FILE* f = fopen(Filename, "r");
    if(f==NULL){
        printf("ReadGraph exit with 1: non existing input file.");
        exit(1);
    }
    
    // Reads the number of vertices and alocate our gaph (adjacency vector).
    fscanf(f, "%d\n", &numVertices);
    graph = (AdjVector)malloc(numVertices*sizeof(List*));

    // Since the adjacency matriz is simetric, we just need to read the elements above 
    //the main diagonal. (at the moment, the function is reading every element)
    for(currentIndex = 0; currentIndex < numVertices; currentIndex++){
        
        graph[currentIndex] = CreateList();
        
        // Each line index corresponds to a node in our graph.
        // The loop below reads each weight of given line and
        //adds it to its current node adjacency list if it's non zero.
        for(targetIndex = 0; targetIndex < numVertices; targetIndex++){
            fscanf(f, "%f", &edgeWeight);
            if(edgeWeight != 0){
                AddToList(graph[currentIndex], targetIndex, edgeWeight);
            }

            // Once the edge is added or not, the next one will be read,
            //so the index of target node is incremented.
            targetIndex++;
        }
    }

    fclose(f);

    return graph;
}