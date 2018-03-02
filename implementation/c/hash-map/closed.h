#ifndef DSA_CLOSED_HASH_MAP_H
#define DSA_CLOSED_HASH_MAP_H


/* Closed hashing hash map
 */


#include <stdint.h>

#include "../utils.h"


typedef struct HashMap {
	uint64_t currentSize;
	uint64_t maxSize;
} HashMap;


typedef struct HashMapNode {
	char* key;
	void* data;
} HashMapNode;


HashMap* hashMapConstruct(uint64_t);

void hashMapDeconstruct(HashMap*);

HashMapNode* hashMapNodeConstruct(char*, void*);

void hashMapNodeDeconstruct(HashMapNode*);


#endif
