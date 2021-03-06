#include "sparse.h"


SparseVector* vectorConstruct(uint64_t cap) {
	SparseVector* vector = malloc(sizeof (*vector));

	if (!cap) {
		cap = DSA_DATA_DEFAULT_SIZE;
	}

	vector -> capacity = cap;
	vector -> array = calloc(cap, sizeof(void*));

	return vector;
}

void vectorDeconstruct(SparseVector* vector, void (*fn)(void*)) {
	if (vector == NULL) {
		return;
	}

	for (uint64_t i = 0; i < vector -> capacity; i++) {
		if (vector -> array[i] != NULL) {
			if (fn != NULL) {
				(*fn)(vector -> array[i]);
			}
			vector -> array[i] = NULL;
		}
	}

	free(vector -> array);
	free(vector);
}

void* vectorGet(const SparseVector* vector, uint64_t index) {
	return vector -> array[index];
}

void vectorSet(SparseVector* vector, uint64_t index, void* data) {
	if (vector -> array[index] == NULL) {
		vector -> size++;
	} else if (data == NULL) {
		vector -> size --;
	}

	vector -> array[index] = data;
}

void vectorClear(SparseVector* vector, void (*fn)(void*)) {
	for (uint64_t i = 0; i < vector -> capacity - 1; i++) {
		if (fn != NULL) {
			(*fn)(vector -> array[i]);
		}
		vector -> array[i] = NULL;
	}
}

void vectorResize(SparseVector* vector, enum Resize action, uint64_t amount, void (*fn)(void*)) {
	uint64_t currentCapacity = vector -> capacity;
	uint64_t proposedSize;

	bool reduction = false;

	switch (action) {
		case ADD:
			proposedSize = currentCapacity + amount;
			break;

		case MULTIPLY:
			proposedSize = currentCapacity * amount;
			break;

		case SUBTRACT:
			proposedSize = max(currentCapacity - amount, 0);
			reduction = true;
			break;

		case DIVIDE:
			proposedSize = currentCapacity / amount;
			reduction = true;
			break;

		case SET:
			proposedSize = amount;
			reduction = proposedSize < currentCapacity;
			break;
	}

	if (reduction) {
		for (uint64_t i = vector -> size; i < vector -> capacity; i++) {
			(*fn)(vector -> array[i]);
		}
	}

	vector -> capacity = proposedSize;
	vector -> array = realloc(vector -> array, sizeof (*(vector -> array)) * (vector -> capacity));
}

char* vectorSprint(SparseVector* vector, char* (*fn)(void*)) {

}

void vectorPrint(SparseVector* vector, void (*fn)(void*)) {
}
