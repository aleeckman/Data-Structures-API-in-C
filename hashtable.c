//
//  hashtable.c
//  Data Structure API in C
//
//  Created by Andrew Eeckman on 5/25/22.
//

#include "hashtable.h"

#define CAPACITY 10000

unsigned long hash_function(int size, char* input) {
    unsigned long hash = 0;
    for (int i = 0; input[i]; i++) hash += (input[i] + i);
    hash %= size;
    return hash;
}

HashItem* createItem(char* key, char* value) {
    HashItem* new_item = malloc(sizeof(HashItem));
    
    new_item->key = key;
    new_item->value = makeDLL();
    insertHead(new_item->value, value);
    
    return new_item;
}

HashTable* createTable(int size) {
    HashTable* new_table = malloc(sizeof(HashTable));
    new_table->items = malloc(size * sizeof(HashItem));
    new_table->size = size;
    new_table->count = 0;
    
    for(int i = 0; i < size; i++) new_table->items[i] = NULL;
    
    return new_table;
}

void freeItem(HashItem* item) {
    deleteDLL(item->value);
    free(item->key);
    free(item);
}

void freeTable(HashTable* table) {
    for (int i = 0; i < table->size; i++)
        if (table->items[i] != NULL) freeItem(table->items[i]);
    free(table->items);
    free(table);
}

void insert(HashTable* table, char* key, char* value) {
    //HashItem* new_item = createItem(key, value);
    
    unsigned long hash = hash_function(table->size, key);
    
    HashItem* current_item = table->items[hash];
    
    if (current_item == NULL) {
        printf("Should print 4 times\n");
        
        if (table->count >= table->size) {
            printf("Insert Error: No Vacancy in Hash Table\n");
            return;
        }
        
        table->items[hash] = createItem(key, value);
        table->count += 1;
    }
    
    else {
        if (getNodeByValue(current_item->value, value) != NULL) {
            printf("Collison Error: Same Value for the Same Key\n");
            return;
        }
        
        insertTail(current_item->value, value);
    }
}

char* searchPeekValue(HashTable* table, char* key) {
    unsigned long hash = hash_function(table->size, key);
    HashItem* current_item = table->items[hash];
    
    if (current_item == NULL) return NULL;
    
    return current_item->value->head->data;
}

node* searchReturnNode(HashTable* table, char* key) {
    unsigned long hash = hash_function(table->size, key);
    HashItem* current_item = table->items[hash];
    
    if (current_item == NULL) return NULL;
    
    return current_item->value->head;
}

void delete_item(HashTable* table, char* key) {
    unsigned long hash = hash_function(table->size, key);
    
    if (table->items[hash] == NULL) {
        printf("Deletion Error: Item is already NULL\n");
        return;
    }
    
    removeHead(table->items[hash]->value);
    
    if (table->items[hash]->value->size == 0) {
        deleteDLL(table->items[hash]->value);
        table->items[hash]->key = NULL;
        table->items[hash] = NULL;
        table->count -= 1;
    }
}

void toStringHashTable(HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        if (table->items[i] != NULL) {
            printf("Key: %s\n", (char*)table->items[i]->key);
            toStringDLL(table->items[i]->value);
        }
    }
}





