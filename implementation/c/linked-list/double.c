#include "double.h"


DoubleList* listConstruct(DoubleListNode* node) {
	DoubleList* list = malloc(sizeof *list);

	if (!node) {
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

void listDeconstruct(DoubleList* list) {
	free(list);
	list = NULL;
}

DoubleListNode* listNodeConstruct(void* data, DoubleListNode* previous, DoubleListNode* next) {
	DoubleListNode* node = malloc(sizeof *node);

	node -> data = data;

	node -> next = next;
	if (next) {
		next -> previous = node;
	}

	node -> previous = previous;
	if (previous) {
		previous -> next = node;
	}

	return node;
}

void listNodeDeconstruct(DoubleListNode* node) {
	free(node -> data);
	free(node);
	node = NULL;
}


void listPush(DoubleList* list, void* data) {
	DoubleListNode* tail = list -> tail;

	DoubleListNode* newElem = listNodeConstruct(data, tail, NULL);

	list -> tail = newElem;
	list -> size++;
}

DoubleListNode* listPop(DoubleList* list) {
	DoubleListNode* tail = list -> tail;
	DoubleListNode* current = tail -> previous;

	current -> next = NULL;
	tail -> previous = NULL;

	list -> tail = current;
	list -> size--;

	return tail;
}

DoubleListNode* listGet(DoubleList* list, int index) {
	if (index < 0 || index >= list -> size) {
		printf("Element not found at index %d - outside of range\n", index);
		return NULL;
	}
	DoubleListNode* node;

	if (index <= (list -> size) / 2) {
		node = list -> head;

		int i = 0;
		while (i < index) {
			if (node != NULL) {
				i++;
				node = node -> next;
			} else {
				printf("Element not found at index %d outside of range\n", index);
				return NULL;
			}
		}
	} else {
		node = list -> tail;

		int i = list -> size - 1;
		while (i > index) {
			if (node != NULL) {
				i--;
				node = node -> previous;
			} else {
				printf("Element not found at index %d outside of range\n", index);
				return NULL;
			}
		}
	}

	return node;
}

void listSet(DoubleList* list, int index, void* newData) {
	DoubleListNode* atIndex = listGet(list, index);

	if (atIndex == NULL) {
		printf("Not setting - aborting...\n");
		return;
	}

	free(atIndex -> data);
	atIndex -> data = newData;
}

void listInsert(DoubleList* list, int index, void* newData) {
	DoubleListNode* previous = listGet(list, index - 1);
	listNodeConstruct(newData, previous, previous -> next);

	list -> size++;
}

void listDelete(DoubleList* list, int index) {
	DoubleListNode* previous = listGet(list, index - 1);
	DoubleListNode* temp = previous -> next;
	DoubleListNode* next = temp -> next;

	previous -> next = next;
	next -> previous = previous;

	listNodeDeconstruct(temp);
	list -> size--;
}

void listClear(DoubleList* list) {
	DoubleListNode* current = list -> head;

	while (current != NULL) {
		DoubleListNode* next = current -> next;
		listNodeDeconstruct(current);

		current = next;
	}

	list -> head = NULL;
	list -> tail = NULL;
	list -> size = 0;
}
