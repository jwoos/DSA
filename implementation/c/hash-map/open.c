#include "open.h"


HashMapNode* hashMapNodeConstruct(char* key, void* value) {
	HashMapNode* hmNode = malloc(sizeof *hmNode);
	if (hmNode == NULL) {
		return hmNode;
	}

	hmNode -> key = key;
	hmNode -> value = value;

	return hmNode;
}

void hashMapNodeDeconstruct(HashMapNode* hmNode, void (*fn)(void*)) {
	if (fn != NULL) {
		fn(hmNode -> value);
	}
	free(hmNode -> key);

	free(hmNode);
}

HashMap* hashMapConstruct(uint32_t capacity) {
	HashMap* htPtr = malloc(sizeof (*htPtr));
	if (!htPtr) {
		return NULL;
	}

	if (!capacity) {
		capacity = DSA_DATA_DEFAULT_SIZE;
	}

	HashMap hm = *htPtr;

	hm.size = 0;
	hm.capacity = capacity;
	hm.vector = vectorConstruct(capacity);

	return htPtr;
}

void hashMapDeconstruct(HashMap* hm, void (*fn)(void*)) {
	vectorDeconstruct(hm -> vector, fn);
	free(hm);
}

void* hashMapGet(HashMap* hm, char* key) {
	uint64_t hash = hashSBDM(key);

	uint32_t index = hash % (hm -> capacity);
	HashMapNode* node = vectorGet(hm -> vector, index);
	Vector* data = current -> data;

	void* val = NULL;

	if (current -> size) {
		for (uint32_t i = 0; i < current.size; i++) {
			if (node -> key == key) {
				val = node -> data;
			}
		}
	}

	return val;
}

void hashMapSet(HashMap* hm, char* key, void* value) {
	uint64_t hash = hashSBDM(key);

	uint32_t index = hash % (hm -> capacity);
	HashMapNode* current = vectorGet(hm -> vector, index);
	Vector* data = current -> data;

	/* performace degradation due to high load
	 * increase capacity and rehash
	 */
	if ((double)hm -> size / hm -> capacity >= 0.65) {
		hashMapResize(hm);
		hashMapRehash(hm);
	}

	if (current.size) {
		bool set = false;
		for (uint32_t i = 0; i < current.size; i++) {
			HashMapNode* node = vectorGet(current, i);
			if (node -> key == key) {
				node -> data = data;
				set = true;
				break;
			}
		}

		if (!set) {
			HashMapNode* node = hashMapNodeConstruct(key, value);
			vectorPush(current, node)
		}
	} else {
		HashMapNode* node = hashMapNodeConstruct(key, data);
		vectorPush(current, node);
	}
}

void hashMapRehash(HashMap* hm) {
}

void hashMapResize(HashMap* hm, enum Resize action, uint32_t factor) {
	uint64_t proposedSize;
	uint64_t currentSize = hm -> size;

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

	hm -> capacity = proposedSize;
	vectorResize(hm -> vector, action, factor);
}
