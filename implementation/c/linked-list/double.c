#include "double.h"


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

void listNodeDeconstruct(DoubleListNode* node, void (*fn)(void*)) {
	if (fn != NULL) {
		fn(node -> data);
	}

	free(node);
}

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

void listDeconstruct(DoubleList* list, void (*fn)(void*)) {
	DoubleListNode* current = list -> head;
	while (current != NULL) {
		DoubleListNode* next = current -> next;

		listNodeDeconstruct(current, fn);

		current = next;
	}

	free(list);
}

void listPush(DoubleList* list, void* data) {
	DoubleListNode* tail = list -> tail;

	DoubleListNode* newElem = listNodeConstruct(data, tail, NULL);

	list -> tail = newElem;
	list -> size++;
}

void* listPop(DoubleList* list) {
	DoubleListNode* tail = list -> tail;
	DoubleListNode* current = tail -> previous;

	current -> next = NULL;
	tail -> previous = NULL;

	list -> tail = current;
	list -> size--;

	void* data = tail -> data;
	listNodeDeconstruct(tail, NULL);

	return tail -> data;
}

void* listGet(DoubleList* list, uint32_t index) {
	if (index < 0 || index >= list -> size) {
		printf("Element not found at index %d - outside of range\n", index);
		return NULL;
	}
	DoubleListNode* node;

	if (index <= (list -> size) / 2) {
		node = list -> head;

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
	} else {
		node = list -> tail;

		uint32_t i = list -> size - 1;
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

	return node -> data;
}

void listSet(DoubleList* list, uint32_t index, void* newData, void (*fn)(void*)) {
	DoubleListNode* current = listGet(list, index);

	if (current == NULL) {
		printf("Not setting - aborting...\n");
		return;
	}

	if (fn != NULL) {
		fn(current -> data);
	}

	current -> data = newData;
}

void listInsert(DoubleList* list, uint32_t index, void* newData) {
	DoubleListNode* previous = listGet(list, index - 1);
	listNodeConstruct(newData, previous, previous -> next);

	list -> size++;
}

void listDelete(DoubleList* list, uint32_t index, void (*fn)(void*)) {
	DoubleListNode* temp = listGet(list, index);
	DoubleListNode* previous = temp -> previous;
	DoubleListNode* next = temp -> next;

	previous -> next = next;
	next -> previous = previous;

	listNodeDeconstruct(temp, fn);
	list -> size--;
}

void listClear(DoubleList* list, void (*fn)(void*)) {
	DoubleListNode* current = list -> head;

	while (current != NULL) {
		DoubleListNode* next = current -> next;
		listNodeDeconstruct(current, fn);

		current = next;
	}

	list -> head = NULL;
	list -> tail = NULL;
	list -> size = 0;
}

void listNodePrint(DoubleListNode* node, bool data) {
	if (data) {
		printf("%d", *(uint32_t*)(node -> data));
	} else {
		printf("%p", node);
	}
}

void listPrint(DoubleList* list) {
	DoubleListNode* current = list -> head;

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
