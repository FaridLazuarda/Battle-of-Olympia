/* File: graph.h */
/* ADT graph dengan representasi multilist */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

// Maksimum simpul dari graph = maks bangunan
#define N  600

// Struktur data
struct Graph {
	// An array of pointers to Node untuk merepresentasikan list
	struct Node* head[N];
};

// A data structure to store adjacency list nodes of the graph
struct Node {
	int dest;
	struct Node* next;
};

// data structure to store graph edges
struct Edge {
	int src, dest;
};

// Function to create an adjacency list from specified edges
struct Graph* createGraph(struct Edge edges[], int n)
{
	unsigned i;

	// allocate memory for graph data structure
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

	// initialize head pointer for all vertices
	for (i = 0; i < N; i++)
		graph->head[i] = NULL;

	// add edges to the directed graph one by one
	for (i = 0; i < n; i++)
	{
		// get source and destination vertex
		int src = edges[i].src;
		int dest = edges[i].dest;

		// 1. allocate new node of Adjacency List from src to dest

		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->dest = dest;

		// point new node to current head
		newNode->next = graph->head[src];

		// point head pointer to new node
		graph->head[src] = newNode;

		// 2. allocate new node of Adjacency List from dest to src

		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->dest = src;

		// point new node to current head
		newNode->next = graph->head[dest];
	
		// change head pointer to point to the new node
		graph->head[dest] = newNode;
		
	}

	return graph;
}

// Function to print adjacency list representation of graph
void printGraph(struct Graph* graph)
{
	int i;
	for (i = 0; i < N; i++)
	{
		// print current vertex and all ts neighbors
		struct Node* ptr = graph->head[i];
		while (ptr != NULL)
		{
			printf("(%d -> %d)\t", i, ptr->dest);
			ptr = ptr->next;
		}

		printf("\n");
	}
}

// Undirected Graph Implementation in C
int main(void)
{
	// input array containing edges of the graph (as per above diagram)
	// (x, y) pair in the array represents an edge from x to y
	struct Edge edges[] =
	{
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	// calculate number of edges
	int n = sizeof(edges)/sizeof(edges[0]);

	// construct graph from given edges
	struct Graph *graph = createGraph(edges, n);

	// print adjacency list representation of graph
	printGraph(graph);

	return 0;
}


#endif