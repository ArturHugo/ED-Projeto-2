#include <stdlib.h>
#include <limits.h>
#include "graph.h"

#include <stdio.h>

int MinKey(Vertice* costKey){
    int i;
    int minIndex;
    float minValue = INF;
    for(i = 0; i < sizeof(costKey); i++){
        if((costKey[i].nodeCost < minValue) && !(costKey[i].isInMst)){
            minValue = costKey[i].nodeCost;
            minIndex = costKey[i].nodeIndex;
        }
    }
    return minIndex;
}

AdjVector Prim(AdjVector graph){
    // Array of mst nodes adjacency lists.
    AdjVector mst;

    int mstTotalNodes;

    // Array that stores the minimal cost to get to each node not yet in
    //the mst and its respective index.
    Vertice* costKey;

    // Auxiliary variables for further for loops.
    int i, j, current = 0;

    // Number of vertices in the graph.
    int graphSize;


    List* currentTarget;

    // Variable to store an edge that leaves the current node.
    Edge currentEdge;

    // Get the graph size and allocate mst and costKey vectors.
    graphSize = sizeof(graph);
    costKey = (Vertice*)malloc(graphSize*sizeof(Vertice));
    mst = (AdjVector)malloc(graphSize*sizeof(Node));
    for(i = 0; i < graphSize; i++){
        mst[i].index = i;
        mst[i].adjList = CreateList();
    }

    for(i = 0; i < graphSize; i++){
        costKey[i].nodeIndex = i;
        costKey[i].nodeCost = graph[i].nodeCost;
        costKey[i].isInMst = 0;
    }

    // The starting node has cost 0.
    costKey[0].nodeCost = 0;

    // Prim's algorithm looping over each node.
    for(current = 0, mstTotalNodes = 0; mstTotalNodes < graphSize; mstTotalNodes++){

        costKey[current].isInMst = 1;

        currentTarget = graph[current].adjList->next;

        // Iterates over each edge conected to the current node.
        while(currentTarget != NULL){
            currentEdge = currentTarget->edge;

            // Update the cost to get to target node if cheaper path was found.
            if(currentEdge.weight < costKey[currentEdge.targetNode].nodeCost){
                costKey[currentEdge.targetNode].nodeCost = currentEdge.weight;
                printf("%f\n", costKey[currentEdge.targetNode].nodeCost);
                // Remove any other edge that leads to this target node
                //through a more expensive path.
                for(i = 0; i < graphSize; i++){
                    RemoveFromEdgeList(mst[i].adjList, currentEdge.targetNode);
                }

                // Add this edge to the mst graph.
                AddToList(mst[current].adjList,
                          currentEdge.targetNode,
                          currentEdge.weight);
            }
            currentTarget = currentTarget->next;
        }
        current = MinKey(costKey);
    }

    return mst;
}