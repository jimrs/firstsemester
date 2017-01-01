#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "graph.h"

#ifndef INIT_SIZE
#define INIT_SIZE 10
#endif

graph_t* allocate_graph() 
{
   	graph_t *graph = (graph_t*) calloc(INIT_SIZE, sizeof(graph_t));
	assert(graph != NULL);
	graph->edges = NULL;
	graph->num_edges = 0;
	graph->capacity = 0;

	return graph;
}

void free_graph(graph_t **graph)
{
	assert(graph != NULL && *graph != NULL);
	if ((*graph)->capacity > 0)
		free((*graph)->edges);

	free(*graph);
	*graph = NULL;
}

graph_t* enlarge_graph(graph_t *graph)
{
	assert(graph != NULL);
	int n = graph->capacity == 0 ? INIT_SIZE : graph->capacity * 2;	//n se bude rovnat - pokud capacity 0 tak INIT SIZE, pokud ne tak capacity * 2

	edge_t *new_edges = (edge_t*)malloc(n * sizeof(edge_t));
	memcpy(new_edges, graph->edges, graph->num_edges * sizeof(edge_t));
	free(graph->edges);
	graph->edges = new_edges;
	graph->capacity = n;

	return graph;
}

void print_graph(graph_t *graph)
{
	assert(graph != NULL);
	fprintf(stderr, "Graph has %d edges and %d edges are allocated\n", graph->num_edges, graph->capacity);
	edge_t *edge = graph->edges;
	for (int i = 0; i < graph->num_edges; ++i, edge++) {
		printf("%d %d %d\n", edge->from, edge->to, edge->cost);
	}
}

void load_txt(const char *fname, graph_t *graph)
{
	int exit = 0;
	FILE *f = fopen(fname, "r");

	while (!feof(f) && !exit) {
		if (graph->num_edges == graph->capacity)
			enlarge_graph(graph);

		edge_t *edge = graph->edges + graph->num_edges;	//posunuti v pameti
		while (!feof(f) && graph->num_edges < graph->capacity) {
			int r = fscanf(f, "%d %d %d\n", &(edge->from), &(edge->to), &(edge->cost));

			if (r == 3) {
				graph->num_edges += 1;
				edge += 1; // posun pointeru
			} else {
				exit = 1; //error
				break;
			}
		}
	}
	fclose(f);
}

void load_bin(const char *fname, graph_t *graph)
{
	FILE *f = fopen(fname, "rb");
	int exit = 0;

	while (!feof(f) && !exit) {
		if (graph->num_edges == graph->capacity)
			enlarge_graph(graph);

		edge_t *edge = graph->edges + graph->num_edges;
		while (!feof(f) && graph->num_edges < graph->capacity) {
			int r = 0;
			r += fread(&(edge->from), sizeof(int), 1, f);
			r += fread(&(edge->to), sizeof(int), 1, f);
			r += fread(&(edge->cost), sizeof(int), 1, f);
			
			if (r == 3) {
				graph->num_edges += 1;
				edge += 1;
			} else {
				exit = 1;
				break;
			}
		}
	}
	fclose(f);
}

void save_txt(const graph_t * const graph, const char *fname)
{
	FILE *f = fopen(fname, "w");
	int pos = 0;
	int size = graph->num_edges;

	while (pos < size) {
		fprintf(f, "%d %d %d\n", graph->edges[pos].from, graph->edges[pos].to, graph->edges[pos].cost);
		pos += 1;
	}
	fclose(f);
}

void save_bin(const graph_t * const graph, const char *fname)
{
	FILE *f = fopen(fname, "wb");

	int pos = 0;
	int size = graph->num_edges;

	while (pos < size) {
		fwrite(&(graph->edges[pos].from), sizeof(int), 1, f);
		fwrite(&(graph->edges[pos].to), sizeof(int), 1, f);
		fwrite(&(graph->edges[pos].cost), sizeof(int), 1, f);
		//fwrite("\n", sizeof(char), 1, f);
		pos += 1;
	}
	fclose(f);
}


