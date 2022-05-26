//
//  linked_list.h
//  Data Structure API in C
//
//  Created by Andrew Eeckman on 5/25/22.
//

#ifndef linked_list_h
#define linked_list_h

#include <string.h>
#include "node.h"

typedef struct dll {
    node* head;
    node* tail;
    int size;
} dll;

/* Creation */
dll* makeDLL(void);

/* Deletion */
void deleteDLL(dll* list);

/* Helpers */
bool isEmpty(dll* list);

/* Apply Function */
typedef void (*dll_func_t)(void *data);
void applyFuncToDLL(dll* list, dll_func_t func);

/* Traversal */
node* getNodeByPos(dll* list, int pos);
node* getNodeByValue(dll* list, void* data);

/* Insertion & Insertion Helpers */
void insertHead(dll* list, void* data);
void insertTail(dll* list, void* data);
void insertNodeAtPos(dll* list, void* data, int pos);

/* Removal & Removal Helpers */
void removeHead(dll* list);
void removeTail(dll* list);
void removeNodeByIndex(dll* list, int pos);
void removeNodeByValue(dll* list, void* data);

/* Converters */
char** createStringArrayFromDLL(dll* list);
dll* createDLLFromCharArray(char** array, int size);

/* Stringify */
void toStringDLL(dll* list);

/* Reverse */
void reverseDLL(dll* list);

/* Merge Sort */
dll* mergeSortDLL(dll* list);

#endif /* linked_list_h */
