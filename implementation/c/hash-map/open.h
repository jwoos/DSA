#ifndef DSA_OPEN_HASH_MAP_H
#define DSA_OPEN_HASH_MAP_H


#include <stdint.h>
#include <stdlib.h>

#include "../vendor/hash.h"

#include "../common.h"
#include "../linked-list/double.h"
#include "../vector.h"


typedef struct HashMapNode {
	uint64_t hash;
	char* key;
	void* value;
} HashMapNode;


typedef struct HashMap {
	uint32_t size;
	uint32_t capacity;
	// vector of linked list
	Vector* vector;
} HashMap;


HashMapNode* hashMapNodeConstruct(char*, void*);

void hashMapNodeDeconstruct(HashMapNode*, void (*fn)(void*));

HashMap* hashMapConstruct(uint32_t);

void hashMapDeconstruct(HashMap*, void (*fn)(void*));

void* hashMapGet(HashMap*, char*);

void hashMapSet(HashMap*, char*, void*);

void hashMapRehash(HashMap*);

void hashMapResize(HashMap*, enum Resize, uint32_t);


#endif
