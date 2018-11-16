#ifndef GRAPH
#define GRAPH
#define INF INT_MAX;

typedef struct Edge {
    int targetNode;
    float weight;
} Edge;

// List structure that will be used as adjacency list.
typedef struct List {
    struct List* next;
    struct Edge edge;
} List;

typedef struct Node {
    int index;
    float nodeCost;
    List* adjList;
} Node;

// Struct to store only the index and the cost of one node.
typedef struct Vertice {
    int nodeIndex;
    int isInMst;
    float nodeCost;
} Vertice;

/* 
An array of adjacency lists (adjacency vector) will represent our graph.
Each index of the array array will correspond to a node or vertice,
while its corresponding adjacency list contains each nodeadjacent to it.
For example: if Graph[1] contains [2,3], the vertices of numbers
2 and 3 are adjacent to the node of number 1.
*/
typedef Node* AdjVector;

List* CreateList();
void AddToList(List* head, int nodeIndex, float edgeWeight);
int RemoveFromEdgeList(List* head, int nodeIndex);
void FreeList(List* head);

AdjVector ReadGraph(char* Filename);

int MinKey(Vertice* costkey);
AdjVector Prim(AdjVector graph);


#endif