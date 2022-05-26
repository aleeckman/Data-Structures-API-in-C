//
//  node.h
//  Data Structure API in C
//
//  Created by Andrew Eeckman on 5/25/22.
//

#ifndef node_h
#define node_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    void* data;
    struct node *next;
    struct node *prev;
} node;

node* makeNode(void* data);
void deleteNode(node* node);

bool hasNext(node* node);
bool hasPrev(node* node);

#endif /* node_h */
