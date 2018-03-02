#ifndef DSA_DOUBLE_LINKED_LIST_H
#define DSA_DOUBLE_LINKED_LIST_H


#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct DoubleList {
	struct DoubleListNode* head;
	struct DoubleListNode* tail;
	uint32_t size;
} DoubleList;


typedef struct DoubleListNode {
	struct DoubleListNode* next;
	struct DoubleListNode* previous;
	void* data;
} DoubleListNode;


DoubleList* listConstruct(DoubleListNode*);

void listDeconstruct(DoubleList*, void (*fn)(void*));

DoubleListNode* listNodeConstruct(void*, DoubleListNode*, DoubleListNode*);

void listNodeDeconstruct(DoubleListNode*, void (*fn)(void*));

void listPush(DoubleList*, void*);

DoubleListNode* listPop(DoubleList*);

DoubleListNode* listGet(DoubleList*, int);

void listSet(DoubleList*, int, void*);

void listDelete(DoubleList*, int);

void listClear(DoubleList*);

void listPrint(DoubleList*);


#endif
