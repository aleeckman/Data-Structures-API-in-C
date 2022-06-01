//
//  main.c
//  Data Structure API in C
//
//  Created by Andrew Eeckman on 5/23/22.
//

#include <stdio.h>
#include <assert.h>
#include "linked_list.h"
#include "hashtable.h"


int main(int argc, const char * argv[]) {
    
    HashTable* table = createTable(50);
    insert(table, "2", "0");
    insert(table, "2", "2");
    insert(table, "2", "6");
    insert(table, "7", "1");
    insert(table, "7", "4");
    insert(table, "11", "3");
    insert(table, "13", "5");
    toStringHashTable(table);
    
    delete_item(table, "2");
    delete_item(table, "11");
    toStringHashTable(table);
    
    return 0;
}
