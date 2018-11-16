#include <stdlib.h>
#include <limits.h>
#include "graph.h"

#include <stdio.h>

#define INF INT_MAX;

int MinKey(float* costkey){
    float minimal = INF;
    int i, minIndex;
    for(i = 0; i < sizeof(costkey); i++){
        if(costkey[i] < minimal){
            minimal = costkey[i];
            minIndex = i;
        }
    }
    return minIndex;
}

AdjVector Prim(AdjVector graph){
    // Array of mst nodes adjacency lists.
    AdjVector mst;

    // Array that stores the minimal cost to get to each node not yet in the mst.
    //E.g.: costKey[i] is the minimal cost to get to the i-th node of the graph.
    float* costKey;

    // Array to store the status of each node.
    //E.g.: if the i-th node is already in the mst, isInMst[i] = 1.
    int* isInMst;

    // Auxiliary variables for further for loops.
    int i, j, current = 0;

    // Number of vertices in the graph.
    int graphSize;

    // Variable to store an edge that leaves the current node.
    Edge currentEdge;

    // Get the graph size and allocate mst, isInMst and costKey vectors.
    graphSize = sizeof(graph);
    costKey = (float*)malloc(graphSize*sizeof(float));
    isInMst = (int*)calloc(graphSize, sizeof(int));
    mst = (AdjVector)malloc(graphSize*sizeof(List*));
    for(i = 0; i < graphSize; i++){
        mst[i] = CreateList();
    }


    // Initialize costKey vector. The first node starts with cost 0
    //and the rest starts with infinite cost to represent that they
    //were not yet reached through any edge.
    costKey[0] = 0;
    for(i = 1; i < graphSize; i++){
        costKey[i] = INF;
    }

    // Prim's algorithm looping over each node.
    for(current = 0; current < graphSize; current++){

        // Iterates over each edge conected to the current node.
        while(graph[current] != NULL){
            currentEdge = graph[current]->next->edge;

            // Update the cost to get to target node if cheaper path was found.
            if(currentEdge.weight < costKey[currentEdge.targetNode]){
                costKey[currentEdge.targetNode] = currentEdge.weight;
                printf("%f\n", costKey[currentEdge.targetNode]);
                // Remove any other edge that leads to this target node
                //through a more expensive path.
                for(i = 0; i < graphSize; i++){
                    RemoveFromEdgeList(mst[i], currentEdge.targetNode);
                }

                // Add this edge to the mst graph.
                AddToList(mst[current],
                          currentEdge.targetNode,
                          currentEdge.weight);
                
            }

            // Adds the adjacent node with cheapest cost key to the mst.
            current = MinKey(costKey);
        }
    }

    return mst;
}