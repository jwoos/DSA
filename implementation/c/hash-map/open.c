#include "open.h"


HashMap* hashMapConstruct(uint64_t size) {
	HashMap* htPtr = malloc(sizeof (*htPtr));

	if (!htPtr) {
		return NULL;
	}

	HashMap ht = *htPtr;

	ht.size = 0;
	ht.capacity = 10;
	ht.store = malloc(sizeof (HashMapNode*) * ht.capacity);

	return htPtr;
}

void hashMapDeconstruct(HashMap* ht) {
	for (uint64_t i = 0; i < ht -> capacity; i++) {
	}

	free(ht -> store);
	free(ht);
}

void hashMapSet(HashMap* ht, char* key, void* data) {
	uint64_t hash = hashSBDM(key);
	uint64_t index = hash % (ht -> capacity);
	HashMapNode current = ht -> store[index];

	/* performace degradation due to high load
	 * increase capacity and rehash
	 */
	if ((double)ht -> size / ht -> capacity >= 0.65) {
		hashMapResize(ht);
		hashMapRehash(ht);
	}

	if (current.size) {
		bool set = false;
		for (uint64_t i = 0; i < current.size; i++) {
			HashMapNode* node = vectorGet(current, i);
			if (node -> key == key) {
				node -> data = data;
				set = true;
				break;
			}
		}

		if (!set) {
			HashMapNode* node = hashMapNodeConstruct(key, data);
			vectorPush(current, node)
		}
	} else {
		HashMapNode* node = hashMapNodeConstruct(key, data);
		vectorPush(current, node);
	}
}

void* hashMapGet(char* key) {
	uint64_t hash = hashSBDM(key);
	uint64_t index = hash % (ht -> capacity);
	Vector current = ht -> store[index];
	void* data = NULL;

	if (current -> size) {
		for (uint64_t i = 0; i < current.size; i++) {
			HashMapNode* node = vectorGet(current, i);
			if (node -> key == key) {
				data = node -> data;
			}
		}
	}

	return data;
}

static void hashMapRehash(HashMap* ht) {
}

void hashMapResize(HashMap* ht, enum Resize action, uint32_t factor) {
	uint64_t proposedSize;
	uint64_t currentSize = ht -> size;

	switch (action) {
		case ADD:
			proposedSize = currentSize + factor;
			break;

		case MULTIPLY:
			proposedSize = currentSize * factor;
			break;

		case SUBTRACT:
			proposedSize = max(currentSize - factor, 0);
			break;

		case DIVIDE:
			proposedSize = currentSize / factor;
			break;

		case SET:
			proposedSize = factor;
			break;
	}

	ht -> capacity = proposedSize;
	vectorResize(ht -> store, MULTIPLY, factor);
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
