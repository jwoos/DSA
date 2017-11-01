#include <stdlib.h>
#include <stdbool.h>

#include "binary-search.h"


BST* bstConstruct(BSTNode* node) {
	BST* bst = malloc(sizeof(BST));

	bst -> root = node ? node : NULL;

	return bst;
}

// TODO
void bstDeconstruct(BST* bst) {
	BSTNode* current = bst -> root;
}

BSTNode* bstNodeInitialize(int data, BSTNode* parent, BSTNode* left, BSTNode* right) {
	BSTNode* node = malloc(sizeof(BSTNode));

	node -> data = data ? data : 0;
	node -> parent = parent ? parent : NULL;
	node -> left = left ? left : NULL;
	node -> right = right ? right : NULL;

	return node;
}

void bstNodeDeconstruct(BSTNode* node) {
	free(node);
}

void bstInsert(BST* bst, int data) {
	BSTNode* current = bst -> root;

	if (current == NULL) {
		return;
	}

	while (true) {
		if (data < current -> data) {
			if (current -> left == NULL) {
				current -> left = bstNodeInitialize(data, current -> left, NULL, NULL);
				break;
			}

			current = current -> left;
		} else {
			if (current -> right == NULL) {
				current -> right = bstNodeInitialize(data, current -> right, NULL, NULL);
				break;
			}

			current = current -> right;
		}
	}
}

void bstDelete(BST* bst, int data) {
	BSTNode* toDelete = bstFind(bst, data);

	if (toDelete == NULL) {
		return;
	}

	BSTNode* parent = toDelete -> parent;

	bool isRoot = bst -> root == toDelete;
	bool hasRight = toDelete -> right != NULL;
	bool hasLeft = toDelete -> left != NULL;

	if (hasRight && hasLeft) {
		BSTNode* temp = toDelete -> right;

		while (temp -> left != NULL) {
			temp = temp -> left;
		}

		toDelete -> data = temp -> data;
		bstDelete(bst, temp);
	} else if (hasRight) {
		BSTNode* rightChild = toDelete -> right;
		toDelete -> data = rightChild -> data;
		toDelete -> left = rightChild -> left;
		toDelete -> right = rightChild -> right;

		if (toDelete -> left != NULL) {
			toDelete -> left -> parent = toDelete;
		}

		if (toDelete -> right != NULL) {
			toDelete -> right -> parent = toDelete;
		}

		bstNodeDeconstruct(rightChild);
	} else if (hasLeft) {
		BSTNode* leftChild = toDelete -> left;
		toDelete -> data = leftChild -> data;
		toDelete -> left = leftChild -> left;
		toDelete -> right = leftChild -> right;

		if (toDelete -> left != NULL) {
			toDelete -> left -> parent = toDelete;
		}

		if (toDelete -> right != NULL) {
			toDelete -> right -> parent = toDelete;
		}

		bstNodeDeconstruct(leftChild);
	} else {
		if (isRoot) {
			bst -> root = NULL;
		} else {
			if (toDelete == toDelete -> paren -> left) {
				toDelete -> parent -> left = NULL;
			} else {
				toDelete -> parent -> right = NULL;
			}
		}
	}

	bstNodeDeconstruct(toDelete);
}

BSTNode* bstFind(BST* bst, int data) {
	BSTNode* current = bst -> root;

	while (current != NULL) {
		if (data == current -> data) {
			break;
		} else if (data < current -> data) {
			current = current -> left;
		} else {
			current = current -> right;
		}
	}

	return current;
}

void bstPrintPreOrder(BST* bst) {
	BSTNode* start = bst -> root;

	if (root != NULL) {
		printf("%d", start -> data);
		printPreOrder(bst, start -> left);
		printPreOrder(bst, start -> right);
	}
}

void bstPrintInOrder(BST* bst) {
	BSTNode* start = bst -> root;

	if (root != NULL) {
		printPreOrder(bst, start -> left);
		printf("%d", start -> data);
		printPreOrder(bst, start -> right);
	}
}

void bstPrintPostOrder(BST* bst) {
	BSTNode* start = bst -> root;

	if (root != NULL) {
		printPreOrder(bst, start -> left);
		printPreOrder(bst, start -> right);
		printf("%d", start -> data);
	}
}

// TODO needs a queue
void bstPrintLevelOrder(BST* bst) {}

static void singleClockwiseRotation() {}

static void singleCounterclockwiseRotation() {}

static void doubleClockwiseRotation() {}

static void doubleCounterclockwiseRotation() {}
