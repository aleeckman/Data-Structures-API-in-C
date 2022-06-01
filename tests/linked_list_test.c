//
//  linked_list_test.c
//  Data Structure API in C
//
//  Created by Andrew Eeckman on 6/1/22.
//

#include "linked_list_test.h"
#include "../linked_list.h"

void test1(void) {
    
    // TODO: NON-OPERATIONAL
    
    dll* new_dll = makeDLL();
    insertHead(new_dll, "Hello");
    insertTail(new_dll, "World");
    insertNodeAtPos(new_dll, ",", 1);
    insertNodeAtPos(new_dll, "New", 2);
    insertTail(new_dll, "Remove Me #1");
    insertNodeAtPos(new_dll, "Remove Me #2", 3);
    toStringDLL(new_dll);
    
    removeTail(new_dll);
    toStringDLL(new_dll);
    
    removeNodeByIndex(new_dll, 3);
    removeNodeByValue(new_dll, ",");
    toStringDLL(new_dll);
    
    char** array = createStringArrayFromDLL(new_dll);
    for (int i = 0; i < new_dll->size; i++) {
        printf("%s\n", array[i]);
    }
    printf("\n");
    free(array);
    
    char* second_array[] = {"Hello", "New", "World", "!", "I AM", "BANA", "woo"};
    dll* second_dll = createDLLFromCharArray(second_array, 7);
    
    toStringDLL(second_dll);
    reverseDLL(second_dll);
    toStringDLL(second_dll);
    
    deleteDLL(new_dll);
    
    dll* sorted_second_dll = mergeSortDLL(second_dll);
    toStringDLL(sorted_second_dll);
    
    deleteDLL(second_dll);
    
}
