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

void FreeList(List* head){
    List* currentNode;
    while((currentNode = head) != NULL){
        head = head->next;
        free(currentNode);
    }
}