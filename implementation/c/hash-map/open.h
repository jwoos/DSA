#ifndef DSA_OPEN_HASH_MAP_H
#define DSA_OPEN_HASH_MAP_H


#include <stdlib.h>

#include "../vendor/hash.h"

#include "../common.h"
#include "../linked-list/double.h"
#include "../vector.h"


typedef struct HashMapNode {
	uint64_t hash;
	char* key;
	void* data;
} HashMapNode;


typedef struct HashMap {
	uint32_t size;
	uint32_t capacity;
	HashMapNode* store;
} HashMap;


HashMap* hashMapConstruct(uint64_t);

void hashMapDeconstruct(HashMap*);

void hashMapSet(HashMap*, char*, void*);

void* hashMapGet(HashMap*, char*);

void hashMapResize(HashMap*, enum Resize, uint64_t);

HashMapNode* hashMapNodeConstruct(char*, void*);

void hashMapNodeDeconstruct(HashMapNode*);


#endif
