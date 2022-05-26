//
//  queue.c
//  Data Structure API in C
//
//  Created by Andrew Eeckman on 5/24/22.
//

#include "queue.h"

queue_pt create_queue(void) {
    queue_pt new_queue = malloc(sizeof(queue_pt));
    new_queue->list = makeDLL();
    return new_queue;
}

void enqueue(queue_pt queue, void* data) {
    insertTail(queue->list, data);
}

void* dequeue(queue_pt queue) {
    void* data = getNodeByPos(queue->list, 0);
    removeHead(queue->list);
    return data;
}

void* peek(queue_pt queue) {
    void* data = getNodeByPos(queue->list, 0);
    return data;
}

void delete_stack(queue_pt queue) {
    deleteDLL(queue->list);
    free(queue);
    queue = NULL;
}

void stringifyQueue(queue_pt queue) {
    toStringDLL(queue->list);
}
