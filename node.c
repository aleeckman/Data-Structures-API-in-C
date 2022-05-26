//
//  node.c
//  Data Structure API in C
//
//  Created by Andrew Eeckman on 5/25/22.
//

#include "node.h"

node* makeNode(void* data) {
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    
    return new_node;
}

void deleteNode(node* node) {
    free(node);
    node = NULL;
}

bool hasNext(node* node) {
    return node->next != NULL;
}

bool hasPrev(node* node) {
    return node->prev != NULL;
}
