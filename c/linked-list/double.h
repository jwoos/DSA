#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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

void listDeconstruct(DoubleList*);

DoubleListNode* listNodeConstruct(void*, DoubleListNode*, DoubleListNode*);

void listNodeDeconstruct(DoubleListNode*);

void listPush(DoubleList*, void*);

DoubleListNode* listPop(DoubleList*);

DoubleListNode* listGet(DoubleList*, int);

void listSet(DoubleList*, int, void*);

void listDelete(DoubleList*, int);

void listClear(DoubleList*);


#endif
