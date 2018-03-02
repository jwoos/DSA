#include <stdlib.h>
#include <stdio.h>

#include "single.h"


SingleListNode* listNodeConstruct(void* data, SingleListNode* next) {
	SingleListNode* node = malloc(sizeof(SingleListNode));
	if (node == NULL) {
		return NULL;
	}

	node -> data = data;
	node -> next = next;

	return node;
}

void listNodeDeconstruct(SingleListNode* node, void (*fn)(void*)) {
	if (fn == NULL) {
		fn = &free;
	}

	fn(node -> data);
	free(node);
}

SingleList* listConstruct(SingleListNode* node) {
	SingleList* list = malloc(sizeof(SingleList));
	if (list == NULL) {
		return NULL;
	}

	if (node == NULL) {
		list -> head = NULL;
		list -> tail = NULL;
		list -> size = 0;
	} else {
		list -> head = node;
		list -> tail = node;
		list -> size = 1;
	}

	return list;
}

void listDeconstruct(SingleList* list, void (*fn)(void)) {
	if (fn == NULL) {
		fn = &free;
	}

	SingleListNode* current = list -> head;
	while (current != NULL) {
		SingleListNode* next = current -> next;

		listNodeDeconstruct(current, fn);

		current = next;
	}

	free(list);
}

void listPush(SingleList* list, void* data) {
	SingleListNode* tail = list -> tail;

	SingleListNode* newElem = listNodeConstruct(data, NULL);

	tail -> next = newElem;
	list -> tail = newElem;
	list -> size++;
}

void* listPop(SingleList* list) {
	SingleListNode* tail = list -> tail;

	SingleListNode* current = list -> head;
	while (current -> next != tail) {
		current = current -> next;
	}

	current -> next = NULL;
	list -> tail = current;
	list -> size--;

	void* data = tail -> data;
	free(tail);

	return tail -> data;
}

void* listGet(SingleList* list, uint32_t index) {
	if (index >= list -> size) {
		printf("Element not found at index %d - outside of range\n", index);
		return NULL;
	}

	SingleListNode* node = list -> head;

	uint32_t i = 0;
	while (i < index) {
		if (node != NULL) {
			i++;
			node = node -> next;
		} else {
			printf("Element not found at index %d outside of range\n", index);
			return NULL;
		}
	}

	return node -> data;
}

void listSet(SingleList* list, uint32_t index, void* newData, void (*fn)(void*)) {
	SingleListNode* current = listGetElement(list, index);

	if (current == NULL) {
		printf("Not setting - aborting...\n");
		return;
	}

	if (fn != NULL) {
		fn(current -> data);
	}

	current -> data = newData;
}

void listInsert(SingleList* list, uint32_t index, void* newData) {
	SingleListNode* previous = listGetElement(list, index - 1);
	SingleListNode* next = previous -> next;

	SingleListNode* newNode = listNodeConstruct(newData, next);
	previous -> next = newNode;

	list -> size++;
}

void listDelete(SingleList* list, uint32_t index, void (*fn)(void*)) {
	if (fn == NULL) {
		fn = &free;
	}

	SingleListNode* previous = listGetElement(list, index - 1);
	SingleListNode* current = prevIndex -> next;

	prevIndex -> next = prevIndex -> next -> next;

	listNodeDeconstruct(temp, fn);
	list -> size--;
}

void listClear(SingleList* list, void (*fn)(void*)) {
	SingleListNode* current = list -> head;

	while (current != NULL) {
		SingleListNode* next = current -> next;
		listNodeDeconstruct(current, NULL);

		current = next;
	}

	list -> head = NULL;
	list -> tail = NULL;
	list -> size = 0;
}

void listNodePrint(SingleListNode* node, bool data) {
	if (data) {
		printf("%d", *(int*)(node -> data));
	} else {
		printf("%p", node);
	}
}

void listPrint(SingleList* list) {
	SingleListNode* current = list -> head;

	while (current != NULL) {
		listNodePrint(current, false);
		printf("[");
		listNodePrint(current, true);
		printf("]");
		printf(" -> ");
		current = current -> next;
	}

	printf("\n");
}
