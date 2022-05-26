//
//  stack.c
//  Data Structure API in C
//
//  Created by Andrew Eeckman on 5/23/22.
//

#include "stack.h"

stack_pt create_stack(void) {
    stack_pt new_stack = malloc(sizeof(stack_pt));
    new_stack->list = makeDLL();
    return new_stack;
}

void push(stack_pt stack, void* data) {
    insertHead(stack->list, data);
}

void* pop(stack_pt stack) {
    void* data = getNodeByPos(stack->list, 0);
    removeHead(stack->list);
    return data;
}

void* peek(stack_pt stack) {
    void* data = getNodeByPos(stack->list, 0);
    return data;
}

void delete_stack(stack_pt stack) {
    deleteDLL(stack->list);
    free(stack);
    stack = NULL;
}
