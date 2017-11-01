#ifndef OPEN_HASH_MAP_H
#define OPEN_HASH_MAP_H


/* Open hashing hash map
 */


#include <stdlib.h>

#include "../linked-list/single.h"


typedef struct HashMap {
	unsigned int currentSize;
	unsigned int maxSize;
	SingleList* store;
} HashMap;

typedef struct HashMapNode {
	char* key;
	void* data;
} HashMapNode;


HashMap* hashMapConstruct(unsigned int);

void hashMapDeconstruct(HashMap*);

HashMapNode* hashMapNodeConstruct(char*, void*);

void hashMapNodeDeconstruct(HashMapNode*);


#endif
