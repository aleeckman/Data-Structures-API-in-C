//
//  stack.h
//  Data Structure API in C
//
//  Created by Andrew Eeckman on 5/23/22.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include "linked_list.h"

struct stack {
    dll* list;
};

typedef struct stack* stack_pt;

stack_pt create_stack(void);
void push(stack_pt stack, void* data);
void* pop(stack_pt stack);
void* peek(stack_pt stack);
void delete_stack(stack_pt stack);

#endif /* stack_h */
