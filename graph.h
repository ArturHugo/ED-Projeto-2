#ifndef GRAPH
#define GRAPH

/* 
An array of adjacency lists will represent our graph.
Each index of the array array will correspond to a node or vertice,
while its corresponding adjacency list contains each nodeadjacent to it.
For example: if Graph[1] contains [2,3], the vertices of numbers
2 and 3 are adjacent to the node of number 1.
*/
typedef List** Graph;


typedef struct Edge {
    int targetNode;
    float weight;
} Edge;
// List structure that will be used as adjacency list.
typedef struct List {
    struct List* next;
    struct Edge edge;
} List;

List* CreateList();
void AddToList(List* head, int nodeIndex);
int RemoveFirstNode(List* head);
void FreeList(List* head);

#endif