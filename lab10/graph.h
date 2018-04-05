#include<stdio.h>
#include<stdlib.h>


typedef struct {
	int val;
}vert;

typedef struct {
	int nv;
	int ne;
	vert* V;
	int** E;
}graph;

typedef graph* Graph;

#define ELEM
typedef vert Element;

Graph createGraph(int numV);

vert* getAdjacent(Graph g, vert v);

Graph addEdge(Graph g, vert v1, vert v2);

int degree(Graph g, vert v);

int bfs(Graph g, vert v);

int f(vert v);

void printg(Graph g);
