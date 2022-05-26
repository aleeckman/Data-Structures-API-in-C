//
//  hashtable.h
//  Data Structure API in C
//
//  Created by Andrew Eeckman on 5/25/22.
//

#ifndef hashtable_h
#define hashtable_h

#include <stdio.h>

typedef struct HashItem {
    void* key;
    void* value;
} HashItem;

typedef struct HashTable {
    HashItem **items;
    int count;
} HashTable;


#endif /* hashtable_h */
