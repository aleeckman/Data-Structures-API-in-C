//
//  hashtable.h
//  Data Structure API in C
//
//  Created by Andrew Eeckman on 5/25/22.
//

#ifndef hashtable_h
#define hashtable_h

#include <stdio.h>
#include <string.h>
#include "linked_list.h"

typedef struct HashItem {
    void* key;
    dll* value;
} HashItem;

typedef struct HashTable {
    HashItem **items;
    int count;
    int size;
} HashTable;

unsigned long hash_function(int size, char* input);

HashItem* createItem(char* key, char* value);
HashTable* createTable(int size);

void freeItem(HashItem* item);
void freeTable(HashTable* table);

void insert(HashTable* table, char* key, char* value);

char* searchPeekValue(HashTable* table, char* key);
node* searchReturnNode(HashTable* table, char* key);

void delete_item(HashTable* table, char* key);

void toStringHashTable(HashTable* table);

#endif /* hashtable_h */
