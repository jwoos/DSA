#ifndef DSA_SPARSE_VECTOR_H
#define DSA_SPARSE_VECTOR_H


#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../common.h"
#include "../utils.h"


typedef struct SparseVector {
	uint64_t size;
	uint64_t capacity;

	void** array;
} SparseVector;


SparseVector* vectorConstruct(uint64_t);

void vectorDeconstruct(SparseVector* vector, void (*fn)(void*));

void* vectorGet(const SparseVector*, uint64_t);

void vectorSet(SparseVector*, uint64_t, void*);

void vectorClear(SparseVector*, void (*fn)(void*));

void vectorResize(SparseVector*, enum Resize, uint64_t, void (*fn)(void*));

char* vectorSprint(SparseVector*, void(*fn)(void*));

void vectorPrint(SparseVector*, void (*fn)(void*));


#endif
