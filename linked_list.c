//
//  linked_list.c
//  Data Structure API in C
//
//  Created by Andrew Eeckman on 5/25/22.
//

#include "linked_list.h"

dll* makeDLL(void) {
    dll* new_dll = malloc(sizeof(dll));
    new_dll->head = NULL;
    new_dll->tail = NULL;
    new_dll->size = 0;
    
    return new_dll;
}

/* Deletion */
void deleteDLL(dll* list) {
    node* current_node = list->head;
    
    while (current_node != NULL) {
        deleteNode(current_node);
        current_node = current_node->next;
    }
    
    list->size = 0;
    
    free(list);
    list = NULL;
}

/* Helpers */
bool isEmpty(dll* list) {
    return list->size == 0;
}

/* TODO: Apply Function */
void applyFuncToDLL(dll* list, dll_func_t func);

/* Traversal */
node* getNodeByPos(dll* list, int pos) {
    
    if (isEmpty(list)) {
        printf("List is Empty\n");
        return NULL;
    }
    
    if (pos < 0) {
        printf("Invalid Position\n");
        return NULL;
    }
    
    if (pos > list->size) {
        printf("Position given exceeds list size. Setting it to end of list instead\n");
        pos = list->size;
    }
    
    if (pos == list->size) return list->tail;
    else if (pos == 0) return list->head;
    
    node* current_node = NULL;
    
    if (pos < list->size/2) {
        current_node = list->head;
        for (int i = 0; i < pos; i++) current_node = current_node->next;
    }
    
    else {
        current_node = list->tail;
        for(int i = list->size-1; i > pos; i--) current_node = current_node->prev;
    }
    
    return current_node;
}

node* getNodeByValue(dll* list, void* data) {
    node* current_node = list->head;
    while (current_node != NULL) {
        if (current_node->data == data) return current_node;
        current_node = current_node->next;
    }
    
    printf("Value not found in list.\n");
    return NULL;
}

/* Insertion & Insertion Helpers */
void insertHead(dll* list, void* data) {
    node *new_node = makeNode(data);
    
    if (isEmpty(list)) {
        list->head = new_node;
        list->tail = new_node;
        list->size += 1;
        return;
    }
    
    node *old_head = list->head;
    list->head = new_node;
    list->head->next = old_head;
    old_head->prev = list->head;
    list->size += 1;
}

void insertTail(dll* list, void* data) {
    node *new_node = makeNode(data);
    
    if (isEmpty(list)) {
        list->head = new_node;
        list->tail = new_node;
        list->size += 1;
        return;
    }
    
    node *old_tail = list->tail;
    list->tail = new_node;
    list->tail->prev = old_tail;
    old_tail->next = list->tail;
    list->size += 1;
}

void insertNodeAtPos(dll* list, void* data, int pos) {
    
    if (pos < 0) {
        printf("Invalid Position\n");
        return;
    }
    
    if (pos > list->size) {
        printf("Position given exceeds list size. Setting it to end of list instead\n");
        pos = list->size;
    }
    
    if (pos == 0) {
        insertHead(list, data);
        return;
        
    } else if(pos == list->size) {
        insertTail(list, data);
        return;
    }
    
    int i = 0;
    node *new_node = makeNode(data);
    node *current_node = list->head;
    
    for(; i < pos; i++) current_node = current_node->next;
    
    new_node->next = current_node;
    new_node->prev = current_node->prev;
    
    current_node->prev->next = new_node;
    current_node->prev = new_node;
    
    list->size += 1;
}

/* Removal & Removal Helpers */
void removeHead(dll* list) {
    
    if (isEmpty(list)) {
        printf("List is already empty\n");
        return;
    }
    
    node* old_head = list->head;
    if (list->head->next != NULL) list->head->next->prev = NULL;
    list->head = list->head->next;
    list->size -= 1;
    
    deleteNode(old_head);
}

void removeTail(dll* list) {
    if (isEmpty(list)) {
        printf("List is already empty\n");
        return;
    }
    
    node* old_tail = list->tail;
    if (list->tail->prev != NULL) list->tail->prev->next = NULL;
    list->tail = list->tail->prev;
    list->size -= 1;
    
    deleteNode(old_tail);
}

void removeNodeByIndex(dll* list, int pos) {
    if (isEmpty(list)) {
        printf("List is Empty\n");
        return;
    }
    
    if (pos < 0 || pos > list->size-1) {
        printf("Invalid Position\n");
        return;
    }
    
    if (pos == 0) {
        removeHead(list);
        return;
        
    } else if (pos == list->size-1) {
        removeTail(list);
        return;
    }
    
    int i = 0;
    node *current_node = list->head;
    
    for(; i < pos; i++) current_node = current_node->next;
    current_node->prev->next = current_node->next;
    current_node->next->prev = current_node->prev;
    list->size -= 1;
    
    deleteNode(current_node);
}

void removeNodeByValue(dll* list, void* data) {
    if (isEmpty(list)) {
        printf("List is Empty\n");
        return;
    }
    
    node *current_node = list->head;
    while (current_node != NULL) {
        if (current_node->data == data) {
            current_node->prev->next = current_node->next;
            current_node->next->prev = current_node->prev;
            deleteNode(current_node);
            list->size -= 1;
            return;
        }
        
        current_node = current_node->next;
    }
    
    printf("Value not found in list.\n");
}

/* Converters */
char** createStringArrayFromDLL(dll* list) {
    if (isEmpty(list)) {
        printf("List is Empty\n");
        return NULL;
    }
    
    node* current_node = list->head;
    char** array = malloc(list->size * sizeof(char*));
    if (!array) return NULL;
    
    for (int i = 0; i < list->size; i++) {
        array[i] = malloc(sizeof(char*));
        if (!array[i]) {
            free(array);
            return NULL;
        }
        
        array[i] = (char *)current_node->data;
        current_node = current_node->next;
    }
    
    return array;
}

dll* createDLLFromCharArray(char** array, int size) {
    if (size < 0) {
        printf("Invalid array size");
        return NULL;
    }
    
    dll* new_dll = makeDLL();
    
    for (int i = 0; i < size; i++) {
        insertNodeAtPos(new_dll, array[i], i);
    }
    
    return new_dll;
}

/* Stringify */
void toStringDLL(dll* list) {
    node* current_node = list->head;
    
    for(int i = 0; i < list->size; i++) {
        printf("Position %d: %s\n", i, (char *)(current_node->data));
        current_node = current_node->next;
    }
    
    printf("\n");
}

/* Reverse */

void reverseDLL(dll* list) {
    if (isEmpty(list)) {
        printf("List is Empty\n");
        return;
    }
    
    node* current_node = list->head;
    node* prev_node = NULL;
    
    for(int i = 0; i < list->size; i++) {
        prev_node = current_node->prev;
        current_node->prev = current_node->next;
        current_node->next = prev_node;
        current_node = current_node->prev;
    }
    
    list->tail = list->head;
    list->head = prev_node->prev;
}

/* Merge Sort & Helper Functions */

int calculateSize(dll* list) {
    int count = 0;
    
    node* current_node = list->head;
    while(current_node != NULL) {
        count += 1;
        current_node = current_node->next;
    }
    
    return count;
}

node* getMiddle(dll* list) {
    node* slow_node = list->head;
    node* fast_node = list->head;
    
    while(fast_node->next != NULL && fast_node->next->next != NULL) {
        slow_node = slow_node->next;
        fast_node = fast_node->next->next;
    }
    
    return slow_node;
}

dll* merge(dll* left, dll* right) {
    dll* merged_dll = makeDLL();
    
    while (left->head != NULL && right->head != NULL) {
        
        if (strcmp((char *)left->head->data, (char*)right->head->data) >= 0) {
            insertTail(merged_dll, left->head->data);
            left->head = left->head->next;
        } else {
            insertTail(merged_dll, right->head->data);
            right->head = right->head->next;
        }
    }
    
    
    while (left->head != NULL) {
        insertTail(merged_dll, left->head->data);
        left->head = left->head->next;
    }

    while (right->head != NULL) {
        insertTail(merged_dll, right->head->data);
        right->head = right->head->next;
    }
    
    return merged_dll;
}

dll* mergeSortDLL(dll* list) {
    if (list->head == NULL || list->head->next == NULL) {
        return list;
    }
    
    node* middle_node = getMiddle(list);
    
    dll* left_dll = malloc(sizeof(dll));
    left_dll->head = list->head;
    left_dll->tail = middle_node;
    //left_dll->size = calculateSize(left_dll);
    
    dll* right_dll = malloc(sizeof(dll));
    right_dll->head = middle_node->next;
    //right_dll->head->prev = NULL;
    right_dll->tail = list->tail;
    //right_dll->size = calculateSize(right_dll);
    right_dll = mergeSortDLL(right_dll);
    
    left_dll->tail->next = NULL;
    left_dll = mergeSortDLL(left_dll);
    
    return merge(left_dll, right_dll);
}
