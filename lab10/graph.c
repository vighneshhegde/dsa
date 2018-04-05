#include"graph.h"


Graph createGraph(int numV){
	Graph g = (Graph)malloc(sizeof(graph));
	g->V = (vert*) malloc(numV*sizeof(vert));
	int i;
	for(i=0;i<numV;i++) g->V[i].val = i;	
	g->E = (int**) malloc (numV *sizeof(int*));
	g->nv = numV;
	g->ne = 0;
	for(i=0;i<numV;i++){
		g->E[i] = (int*)calloc(numV,sizeof(int));
	}
	return g;
}

vert* getAdjacent(Graph g, vert v){
	vert* V = NULL;

	int i,j=f(v), count = 0;
	for(i=0;i<g->nv;i++){
		if(g->E[j][i]==1){
			count++;
			V = realloc(V, count*sizeof(vert));
			V[count-1] = g->V[i];
		}
	}
	return V;
}

Graph addEdge(Graph g, vert v1, vert v2){
	g->E[f(v1)][f(v2)] = 1;
	g->ne++;
	return g;
}

int degree(Graph g, vert v){
	int count =0, i;	
	for(i=0;i<g->nv;i++){
		if(g->E[f(v)][i]==1){
			count++;
		}
	}
	return count;
}

int f(vert v){
	return v.val;
}

void printg(Graph g){
	printf("nv = %d, ne = %d\n",g->nv,g->ne);
	printf("vertices:\n");
	int i,j;
	for(i=0;i<g->nv;i++){printf("%d ", g->V[i].val);}
	printf("\nEdges:\n");
	for(i=0;i<g->nv;i++){
		for(j=0;j<g->nv;j++){
			printf("%d ",g->E[i][j]);
		}
		printf("\n");
	}
}
	
