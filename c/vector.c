#include <stdlib.h>
#include <stdio.h>

#include "vector.h"

static void increaseCapacity(Vector* vector) {
	vector -> capacity *= 2;

	vector -> arr = realloc(vector -> arr, sizeof(int) * (vector -> capacity));
}

Vector* vectorConstruct() {
	Vector* vector = malloc(sizeof(Vector));

	vector -> size = 0;
	vector -> capacity = 1;
	vector -> arr = malloc(sizeof(int));

	return vector;
}

void vectorDeconstruct(Vector* vector) {
	free(vector -> arr);
	free(vector);

	vector = NULL;
}

void vectorPrint(const Vector* vector) {
	for (int i = 0; i < vector -> size; i++) {
		printf("%d -> ", vector -> arr[i]);
	}

	printf("\n");
}

void vectorPush(Vector* vector, int data) {
	if (vector -> size == vector -> capacity) {
		increaseCapacity(vector);
	}

	vector -> arr[vector -> size] = data;
	vector -> size++;
}

int vectorPop(Vector* vector) {
	vector -> size--;

	int data = vector -> arr[vector -> size];
	vector -> arr[vector -> size] = 0;

	return data;
}

int vectorGet(const Vector* vector, int index) {
	return vector -> arr[index];
}

void vectorSet(Vector* vector, int index, int data) {
	vector -> arr[index] = data;
}

void vectorInsert(Vector* vector, int index, int data) {
	if (vector -> size == vector -> capacity) {
		increaseCapacity(vector);
	}

	vector -> size++;

	for (int i = vector -> size - 1; i > index; i--) {
		vector -> arr[i] = vectorGet(vector, i - 1);
	}

	vectorSet(vector, index, data);
}

void vectorDelete(Vector* vector, int index) {
	for (int i = index; i < vector -> size - 1; i++) {
		vector -> arr[i] = vectorGet(vector, i + 1);
	}

	vector -> size--;
}

void vectorClear(Vector* vector) {
	free(vector -> arr);
	vector -> arr = malloc(sizeof(int));
	vector -> size = 0;
	vector -> capacity = 1;
}
