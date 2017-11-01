#ifndef VECTOR_H
#define VECTOR_H


typedef struct Vector {
	int size;
	int capacity;
	int* arr;
} Vector;

Vector* vectorConstruct();

void vectorDeconstruct(Vector*);

void vectorPrint(const Vector*);

void vectorPush(Vector*, int);

int vectorPop(Vector*);

int vectorGet(const Vector*, int);

void vectorSet(Vector*, int, int);

void vectorInsert(Vector*, int, int);

void vectorDelete(Vector*, int);

void vectorClear(Vector*);


#endif
