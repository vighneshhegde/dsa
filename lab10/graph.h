#include<stdio.h>
#include<stdlib.h>


typedef struct {
	int val;
}vert;

#define ELEM
#define ELEMENT
typedef vert Element;

#ifdef ADJMAT
typedef struct {
	int nv;
	int ne;
	vert* V;
	int** E;
}graph;
#endif

#ifdef ADJLIST
#include"linklist.h"

typedef struct{
	int nv;
	int ne;
	vert* V;
	List* E;
}graph;
#endif
typedef graph* Graph;

Graph readFile(FILE* f);
Graph createGraph(int numV);

vert* getAdjacent(Graph g, vert v);

Graph addEdge(Graph g, vert v1, vert v2);

int degree(Graph g, vert v);

int bfs(Graph g, vert v);

int f(vert v);

void printg(Graph g);
