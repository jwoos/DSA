#ifndef DSA_GRAPH_H
#define DSA_GRAPH_H


typedef struct AdjacencyListNode {
	int index;
	struct AdjacencyListNode* to;
} AdjacencyListNode;


typedef struct AdjacencyList {
	AdjacencyListNode* head;
} AdjacencyList;


typedef struct Graph {
	union {
		AdjacencyList list;
		int** matrix;
	} data;
	enum {
		MATRIX,
		LIST
	} type;
	int vertexCount;
	int edgeCount;
	bool directed;
} Graph;


int** matrixInitialize(int);

AdjacencyList* listInitialize(int);

Graph* graphInitialize(int);

void matrixDeconstruct(AdjacencyMatrix*);

void listDeconstruct(AdjacencyList*);

void graphDeconstruct(Graph*);


#endif
