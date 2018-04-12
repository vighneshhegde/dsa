#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int val;
	int indeg;
	int visited:1;//0 if no, 1 if yes.
}vert;

typedef struct{
	vert* from;
	vert* to;
	int visited:1;
}edge;

#define ELEMENT
typedef edge* Element;

#include"linklist.h"

typedef struct {
	int nv;
	int ne;
	vert* V;
	list* Elist;		
}graph;

typedef graph* Graph;

Graph createGraph();
Graph readFile(FILE* f);
vert* addV(Graph g, int v);
Graph addEdge(Graph g, int v1, int v2);

void printg(Graph g);

vert* getAdjacent(Graph g, vert v);


int degree(Graph g, vert v);

int bfs(Graph g, vert v);

int f(vert v);

