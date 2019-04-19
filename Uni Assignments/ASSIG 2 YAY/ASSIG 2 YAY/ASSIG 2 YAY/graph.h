#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
	int to_vertex;
	int weight;
} Edge;

typedef struct edgeNode {
	Edge edge;
	struct edgeNode *next;
} *EdgeNodePtr;

typedef struct edgeList {
	EdgeNodePtr head;
} EdgeList;

typedef struct graph {
	int V;
	EdgeList *edges;
} Graph;

void floyd_warshall_with_path_reconstruction(Graph edge, int **dist, int ** next);
int Path(int **next, int u, int v);
void centrality(int *path, int *cent, int total_edges);