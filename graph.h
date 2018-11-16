#ifndef GRAPH
#define GRAPH

typedef struct Edge {
    int targetNode;
    float weight;
} Edge;

// List structure that will be used as adjacency list.
typedef struct List {
    struct List* next;
    struct Edge edge;
} List;

/* 
An array of adjacency lists (adjacency vector) will represent our graph.
Each index of the array array will correspond to a node or vertice,
while its corresponding adjacency list contains each nodeadjacent to it.
For example: if Graph[1] contains [2,3], the vertices of numbers
2 and 3 are adjacent to the node of number 1.
*/
typedef List** AdjVector;

List* CreateList();
void AddToList(List* head, int nodeIndex, float edgeWeight);
void FreeList(List* head);

AdjVector ReadGraph(char* Filename);

#endif