#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

//Function similar to Wikipedia resource provided in handout
void floyd_warshall_with_path_reconstruction(Graph G, int **dist, int **next) {
	int vertex;				//Stores current vertex
	int weight;				//Stores current weight (1);
	EdgeNodePtr current1;	//Stores a EdgeNodePtr for adjusting next fields
	
	
	for (int u = 0; u < G.V; u++) {
		current1 = G.edges[u].head;
		dist[u][u] = 0;
		next[u][u] = NULL;
		while (current1 != NULL) {
			vertex = current1->edge.to_vertex;
			weight = current1->edge.weight;
			dist[u][vertex] = weight;
			next[u][vertex] = vertex;
			current1 = current1->next;
		}
	}


	for (int k = 0; k < G.V; k++) {
		for (int i = 0; i < G.V; i++) {
			for (int j = 0; j < G.V; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					next[i][j] = next[i][k];
				}
			}
		}
	}
}

//Function similar to Wikipedia resource provided in handout
//Returns the path 
int Path(int **next, int u, int v) {
	if (next[u][v] == NULL) {
		return(NULL);
	}
	int path;
	if (u != v){
		u = next[u][v];
		path = u;
	}
	return path;
}

//Calculates centrality
void centrality(int *path, int *cent,int total_edges) {
		for (int counter = 0; counter < total_edges; counter++) {
			if (path[counter] != NULL) {
				cent[path[counter]] = cent[path[counter]] + 1;
				counter = counter + 1;
			}
	}
}