//
//  queue.h
//  Data Structure API in C
//
//  Created by Andrew Eeckman on 5/24/22.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include "linked_list.h"

struct queue {
    dll* list;
};

typedef struct queue* queue_pt;

queue_pt create_queue(void);
void enqueue(queue_pt queue, void* data);
void* dequeue(queue_pt queue);
void* peek(queue_pt queue);
void delete_queue(queue_pt queue);

#endif /* queue_h */
