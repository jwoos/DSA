#include <stdlib.h>
#include <stdio.h>

#include "tree/binary-search.h"
#include "linked-list/single.h"
#include "vector.h"


void listCheck() {
	SingleListNode* head = listNodeConstruct(10, NULL);
	SingleList* list = listConstruct(head);

	for (int i = 2; i < 10; i++) {
		listPush(list, i * 10);
	}

	listPrint(list);

	SingleListNode* popped = listPop(list);

	listPrint(list);
	printf("popped address: %p data: %d\n", (void*) popped, popped -> data);

	printf("index 2: %d\n", listGetElement(list, 2) -> data);
	printf("index 10: %p\n", (void*)listGetElement(list, 10));

	listSetElement(list, 2, 1000);
	printf("index 2: %d\n", listGetElement(list, 2) -> data);

	listInsert(list, 5, 2000);
	listPrint(list);
	listDelete(list, 5);
	listPrint(list);

	listClear(list);
	listPrint(list);
	printf("size: %d, head: %p tail: %p\n", list -> size, (void*)list -> head, (void*)list -> tail);

	free(popped);
	free(list);
}

void vectorCheck() {
	Vector* vector = vectorConstruct();
	for (int i = 0; i < 100; i++) {
		vectorPush(vector, i);

		printf("size: %d, capacity: %d \n", vector -> size, vector -> capacity);
	}
	vectorPrint(vector);

	printf("popped data:");
	for (int i = 0; i < 50; i++) {
		printf(" %d,", vectorPop(vector));
	}
	printf("\n");
	printf("size: %d, capacity: %d \n", vector -> size, vector -> capacity);
	vectorPrint(vector);

	vectorInsert(vector, 10, 100);
	vectorPrint(vector);
	vectorDelete(vector, 10);
	vectorPrint(vector);
	vectorClear(vector);
	printf("size: %d, capacity: %d \n", vector -> size, vector -> capacity);

	free(vector -> arr);
	free(vector);
}

void bstCheck() {
	/*BST* bst = bstConstruct();*/
}

int main() {
	return 0;
}
