#ifndef DSA_BINARY_SEARCH_TREE_H
#define DSA_BINARY_SEARCH_TREE_H


typedef struct BSTNode {
	int data;
	struct BSTNode* left;
	struct BSTNode* right;
	struct BSTNode* parent;
} BSTNode;


typedef struct BST {
	BSTNode* root;
} BST;


BST* bstConstruct(BSTNode*);

void bstDeconstruct(BST*);

BSTNode* bstNodeInitialize(int, BSTNode*, BSTNode*, BSTNode*);

void bstNodeDeconstruct(BSTNode*);

void bstInsert(BST*, int);

void bstDelete(BST*, int);

BSTNode* bstFind(BST*, int);

void bstPrintPreOrder(BST*);

void bstPrintInOrder(BST*);

void bstPrintPostOrder(BST*);

void bstPrintLevelOrder(BST*);


#endif
