#include <stdlib.h>
#include <stdbool.h>

#include "graph.h"


int** matrixInitialize(int size) {
	if (!size) {
		size = 5;
	}

	int** matrix = malloc(sizeof(int*) * size);

	for (int i = 0; i < size; i++) {
		matrix[i] = calloc(size, sizeof(int));
	}

	return matrix;
}

Graph* graphInitialize(int type, bool directed, int vertexCount) {
	Graph* graph = malloc(sizeof(Graph));

	graph -> vertexCount = vertexCount;
	graph -> directed = directed;

	if (type == MATRIX) {
		graph -> data = matrixInitialize(vertexCount);
	} else {
		graph -> data = listInitialize(vertexCount);
	}

	return graph;
}

void graphSet(Graph* graph, int from, int to, int state) {
	if (graph -> type == MATRIX) {
		int** matrix = graph -> data.matrix;
		matrix[from][to] = state;
	} else {
	}
}

void graphDeconstruct(Graph* graph) {
	if (graph -> type == MATRIX) {
		int** matrix = graph -> data.matrix;
	}
}
