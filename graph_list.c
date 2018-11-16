#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

List* CreateList(){
    List* head;
    head = (List*)malloc(sizeof(List));
    
    if(head == NULL){
        printf("CreateList exit with 1: couldn't allocate create list.");
        exit(1);
    }

    head->edge.targetNode = 0;
    head->edge.weight = 0;
    head->next = NULL;
    return head;
}

void AddToList(List* head, int nodeIndex, float edgeWeight){
    List* current = head;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = (List*)malloc(sizeof(List));
    current->next->edge.targetNode = nodeIndex;
    current->next->edge.weight = edgeWeight;
    current->next->next = NULL;
}

int RemoveFromEdgeList(List* head, int nodeIndex){
    List* current = head;

    // The negative value is to indicate that an edge that leads to
    //nodeIndex was not found, since there is no negative index for nodes.
    int removedEdge = -1;

    while((current != NULL)){
        if(current->edge.targetNode == nodeIndex){
            removedEdge = current->edge.targetNode;
            break;
        }
        current = current->next;
    }

    // If no edge was found, return 0;
    if(!(removedEdge+1)){
        return  0;
    }

    // Else, remove that edge and returns 1.
    free(current);
    return 1;
}

void FreeList(List* head){
    List* currentNode;
    while((currentNode = head) != NULL){
        head = head->next;
        free(currentNode);
    }
}