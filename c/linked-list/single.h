#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

/*
 * the SingleListNode is the actual list, I opted to wrap it in another struct
 * to avoid having to put the head/tail on each SingleListNode as that would be
 * highly inefficient. Also this way, other properties of the list as
 * a WHOLE can be recorded e.g. size
 */

// this should still be available
typedef struct SingleListNode {
	int data;
	struct SingleListNode* next;
} SingleListNode;

// SingleListNode wrapper
typedef struct SingleList {
	SingleListNode* head;
	SingleListNode* tail;
	int size;
} SingleList;

SingleList* listConstruct(SingleListNode*);

void listDeconstruct(SingleList*);

SingleListNode* listNodeInitialize(int, SingleListNode*);

void listNodeDeconstruct(SingleListNode*);

void listPrint(SingleList*);

void listPush(SingleList*, int);

SingleListNode* listPop(SingleList*);

SingleListNode* listGetElement(SingleList*, int);

void listSetElement(SingleList*, int, int);

void listInsert(SingleList*, int, int);

void listDelete(SingleList*, int);

void listClear(SingleList*);

#endif
