#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
	Graph G;						//Graph used to store all the vertices
	G.V = malloc(sizeof(int));
	int abc;						//Generic storage of data obtained from the file
	FILE *input1;					//The file
	int vertex;						//The vertex obtained from the file
	int *path = (int *)malloc(sizeof(int) * G.V);	//Store the path as an array of ints
	
	input1 = fopen("input1.txt", "r");
	fscanf(input1, "%d", &abc);		//Gets number of nodes
	G.V = abc;
	//Mallocs centrality to be an array of ints
	int *cent = (int*)malloc(sizeof(int) * G.V);
	for (int z = 0; z < abc; z++) {
		cent[z] = 0;
	}

	//Mallocs dist to be an array of arrays of ints
	int **dist =(int **)malloc(sizeof(int *) * abc);
	for (int a = 0; a < abc; a++) {
		dist[a] = malloc(sizeof(int) * abc);
		for (int z = 0; z < abc; z++) {
			dist[a][z] = 1000000000;
		}
	}

	//Mallocs next to be an array of arrays of ints
	int **next = (int **)malloc(sizeof(int *) * abc);
	for (int a = 0; a < abc; a++) {
		next[a] = malloc(sizeof(int) * abc);
		for (int z = 0; z < abc; z++) {
			next[a][z] = NULL;
		}
	}
		
	G.edges = malloc(sizeof(EdgeList) * G.V);



	//Arranges graph by adding vertices
	for (int i = 0; i < G.V; i++) {
		G.edges[i].head = NULL;
		fscanf(input1, "%d", &abc);
		for (int j = 0; j < abc; j++) {
			EdgeNodePtr new_node = malloc(sizeof *new_node);
			fscanf(input1, "%d", &vertex);
			new_node->edge.to_vertex = vertex;
			new_node->edge.weight = 1;
			new_node->next = G.edges[i].head;
			G.edges[i].head = new_node;
		}
	}

	//Floyd warshall algorithm
	floyd_warshall_with_path_reconstruction(G, dist, next);

	//Loops through Path function
	for (int i = 0; i < G.V; i++) {
		for (int j = 0 + 1; j < G.V; j++) {
			int u = i;			//Storage of current iteration (changeable)
			int v = j;			//Storage of current iteration (changeable)
			int counter = 0;	//Counts iterations in while loop
			
			//Sets all of path to be null
			for (int x = 0; x < G.V; x++) {
				path[x] = NULL;
			}

			//Loops through Path function and stores input into path array
			while (Path(next, u, v) != NULL && next[u][v] != v) {
				path[counter] = Path(next, u, v);
				u = path[counter];
				counter = counter + 1;
			}

			centrality(path, cent, G.V);
		}
	}

	//Prints output
	for (int x = 0; x < G.V; x++) {
		printf("%d: %d\n", x, cent[x]);
	}
	fclose(input1);
}