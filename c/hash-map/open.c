#include "open.h"


HashMap* hashMapConstruct(unsigned int s) {
	HashMap* hm = malloc(sizeof *hm);
	if (!hm) {
		return NULL;
	}

	hm -> currentSize = 0;
	hm -> maxSize = s;

	ListNode* head = malloc(sizeof *head);
	hm -> store = listConstruct(head);

	return hm;
}

void hashMapDeconstruct(HashMap* hm) {
	listDeconstruct(hm -> store);
	free(hm);
	hm = NULL;
}

HashMapNode* hashMapNodeConstruct(char* key, void* data) {
	HashMapNode* hmNode = malloc(sizeof *hmNode);
	hmNode -> key = key;
	hmNode -> data = data;

	return hmNode;
}

void hashMapNodeDeconstruct(HashMapNode* hmNode) {
	free(hmNode);
}
