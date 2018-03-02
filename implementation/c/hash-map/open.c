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
	if (hmNode == NULL) {
		return;
	}

	if (fn != NULL) {
		fn(hmNode -> value);
	}
	free(hmNode -> key);

	free(hmNode);
}

HashMap* hashMapConstruct(uint64_t capacity) {
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
	if (hm == NULL) {
		return;
	}

	vectorDeconstruct(hm -> vector, fn);
	free(hm);
}

void* hashMapGet(HashMap* hm, char* key) {
	uint64_t hash = hashSBDM(key);

	uint64_t index = hash % (hm -> capacity);
	SingleList* list = vectorGet(hm -> vector, index);

	void* val = NULL;

	if (list != NULL) {
		SingleListNode* node = list -> head;
		while (node != NULL) {
			if (node -> data -> key == key) {
				val = node -> data -> value;
			}

			node = node -> next;
		}
	}

	return val;
}

void hashMapSet(HashMap* hm, char* key, void* value, void (*fn)(void*)) {
	uint64_t hash = hashSBDM(key);

	uint64_t index = hash % (hm -> capacity);
	SingleList* list = vectorGet(hm -> vector, index);

	/* performace degradation due to high load
	 * increase capacity and rehash
	 */
	if ((double) hm -> size / (double) hm -> capacity >= DSA_DATA_RESIZE_THRESHOLD) {
		hashMapResize(hm);
		hashMapRehash(hm);
	}

	if (list != NULL) {
		bool set = false;

		SingleListNode* node = list -> head;
		while (node != NULL) {
			if (node -> data -> key == key) {
				if (fn != NULL) {
					(*fn)(node -> data -> value);
				}

				node -> data -> value = value;
				set = true;
				break;
			}

			node = node -> next;
		}

		if (!set) {
			HashMapNode* node = hashMapNodeConstruct(key, value);
			listPush(list, node);
			hm -> size++;
		}
	} else {
		list = listConstruct(NULL);
		HashMapNode* node = hashMapNodeConstruct(key, value);
		listPush(list, node);

		vectorSet(hm -> vector, index, list, NULL);
		hm -> size++;
	}
}

void hashMapDelete(HashMap* hm, char* key, void (*fn)(void*)) {
	uint64_t hash = hashSBDM(key);

	uint64_t index = hash % (hm -> capacity);
	SingleList* list = vectorGet(hm -> vector, index);

	if (list != NULL) {
		SingleListNode* node = list -> head;
		while (node != NULL) {
			if (node -> data -> key == key) {
				hashMapNodeDeconstruct(node -> data, fn);
				break;
			}

			node = node -> next;
		}
	}
}

bool hashMapExists(HashMap* hm, char* key) {
	uint64_t hash = hashSBDM(key);

	uint64_t index = hash % (hm -> capacity);
	SingleList* list = vectorGet(hm -> vector, index);

	bool found = false;

	if (list != NULL) {
		SingleListNode* node = list -> head;
		while (node != NULL) {
			if (node -> data -> key == key) {
				found = true;
			}

			node = node -> next;
		}
	}

	return found;
}

void hashMapRehash(HashMap* hm) {
	HashMapNode** holder = malloc(sizeof (HashMapNode*) * hm -> size);
	uint64_t index = 0;

	for (uint64_t i = 0; i < hm -> capacity; i++) {
		SingleList* list = vectorGet(hm -> vector, i);
		if (list == NULL) {
			continue;
		}

		SingleListNode* node = list -> head;
		while (node != NULL) {
			holder[index] = node -> data;
			node = node -> next;
		}

		listDeconstruct(list, NULL);
	}

	for (uint64_t i = 0; i < hm -> size; i++) {
		HashMapNode* node = holder[i];
		hashMapSet(hm, node -> key, node -> value, NULL);
		hashMapNodeDeconstruct(node, NULL);
	}

	free(holder);
}

void hashMapResize(HashMap* hm, enum Resize action, uint64_t factor) {
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
