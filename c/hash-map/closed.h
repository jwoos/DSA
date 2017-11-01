#ifndef CLOSED_HASH_MAP_H
#define CLOSED_HASH_MAP_H


/* Closed hashing hash map
 */


#include <stdint.h>

#include "../utils.h"


typedef struct HashMap {
	unsigned int currentSize;
	unsigned int maxSize;
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
