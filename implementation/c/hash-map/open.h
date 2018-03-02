#ifndef DSA_OPEN_HASH_MAP_H
#define DSA_OPEN_HASH_MAP_H


#include <stdint.h>
#include <stdlib.h>

#include "../vendor/hash.h"

#include "../common.h"
#include "../linked-list/single.h"
#include "../vector/sparse.h"


typedef struct HashMapNode {
	uint64_t hash;
	char* key;
	void* value;
} HashMapNode;


typedef struct HashMap {
	uint64_t size;
	uint64_t capacity;
	// vector of linked list
	SparseVector* vector;
} HashMap;


HashMapNode* hashMapNodeConstruct(char*, void*);

void hashMapNodeDeconstruct(HashMapNode*, void (*fn)(void*));

HashMap* hashMapConstruct(uint64_t);

void hashMapDeconstruct(HashMap*, void (*fn)(void*));

void* hashMapGet(HashMap*, char*);

void hashMapSet(HashMap*, char*, void*, void (*fn)(void*));

void hashMapDelete(HashMap*, char*, void (*fn)(void*));

bool hashMapExists(HashMap*, char*);

void hashMapRehash(HashMap*);

void hashMapResize(HashMap*, enum Resize, uint64_t);


#endif
