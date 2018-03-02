#ifndef DSA_SINGLE_LINKED_LIST_H
#define DSA_SINGLE_LINKED_LIST_H


#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


/*
 * the SingleListNode is the actual list, I opted to wrap it in another struct
 * to avoid having to put the head/tail on each SingleListNode as that would be
 * highly inefficient. Also this way, other properties of the list as
 * a WHOLE can be recorded e.g. size
 */

// this should still be available
typedef struct SingleListNode {
	void* data;
	struct SingleListNode* next;
} SingleListNode;


// SingleListNode wrapper
typedef struct SingleList {
	SingleListNode* head;
	SingleListNode* tail;
	uint64_t size;
} SingleList;


SingleListNode* listNodeConstruct(void*, SingleListNode*);

void listNodeDeconstruct(SingleListNode*, void (*fn)(void*));

SingleList* listConstruct(SingleListNode*);

void listDeconstruct(SingleList*, void (*fn)(void*));

void listPrint(SingleList*);

void listPush(SingleList*, void*);

void* listPop(SingleList*);

void* listGet(SingleList*, uint64_t);

void listSet(SingleList*, uint64_t, void*, void (fn*)(void*));

void listInsert(SingleList*, uint64_t, void*);

void listDelete(SingleList*, uint64_t, void (fn*)(void*));

void listClear(SingleList*, void (fn*)(void*));

void listNodePrint(SingleListNode*, bool);

void listPrint(SingleList*);


#endif
