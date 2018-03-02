#ifndef DSA_SPARSE_VECTOR_H
#define DSA_SPARSE_VECTOR_H


#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../common.h"
#include "../utils.h"


typedef struct SparseVector {
	uint64_t capacity;

	void** array;
} SparseVector;


SparseVector* vectorConstruct(uint64_t);

void vectorDeconstruct(SparseVector* vector, void (*fn)(void*));

void vectorPush(SparseVector*, void*);

void* vectorPop(SparseVector*);

void* vectorGet(const SparseVector*, uint64_t);

void vectorSet(SparseVector*, uint64_t, void*);

void vectorInsert(SparseVector*, uint64_t, void*);

void vectorDelete(SparseVector*, uint64_t, void (*fn)(void*));

void vectorClear(SparseVector*, void (*fn)(void*));

void vectorResize(SparseVector*, enum Resize, uint64_t);

char* vectorSprint(SparseVector*, void(*fn)(void*));

void vectorPrint(SparseVector*, void (*fn)(void*));


#endif
