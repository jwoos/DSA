#ifndef DSA_DOUBLE_LINKED_LIST_H
#define DSA_DOUBLE_LINKED_LIST_H


#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct DoubleList {
	struct DoubleListNode* head;
	struct DoubleListNode* tail;
	uint64_t size;
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

DoubleListNode* listGet(DoubleList*, uint64_t);

void listSet(DoubleList*, uint64_t, void*, void (*fn)(void*));

void listDelete(DoubleList*, uint64_t, void (*fn)(void*));

void listClear(DoubleList*, void (*fn)(void*));

void listNodePrint(DoubleListNode*, bool);

void listPrint(DoubleList*);


#endif
