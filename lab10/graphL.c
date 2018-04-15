#define ADJLIST
#include"graph.h"

Graph readFile(FILE* f){
	Graph g = createGraph(8);
	vert v1,v2;
	int i1,i2;
	while(!feof(f)){
		fscanf(f,"%d %d\n",&i1,&i2);
		v1.val = i1; v2.val=i2;
		g = addEdge(g, v1, v2);
	}
	return g;
}

Graph createGraph(int numV){
	Graph g = (Graph)malloc(sizeof(graph));
	g->E = NULL;
	g->V = NULL;
	g->nv = 0;
	g->ne = 0;
/*
	int i;
	for(i=0;i<numV;i++) g->V[i].val = i;	
	for(i=0;i<numV;i++){
		g->E[i] = (int*)calloc(numV,sizeof(int));
	}
*/
	return g;
}

vert* getAdjacent(Graph g, vert v){
	vert* V = NULL;

	int i,j, count = 0;
	for(i=0;i<g->nv;i++){
		if(f(g->V[i])==f(v)){
			node* current = g->E[i]->head;
			V=(vert*)malloc(g->E[i]->length*sizeof(vert));
			for(j=0;current!=NULL;current=current->next){
				V[j] = current->e;
			}
		}
	}
	return V;
}

Graph addEdge(Graph g, vert v1, vert v2){
	int added=0;
	int i;
	node* new = (node*)malloc(sizeof(node));
	new->e = v2;
	new->next = NULL;
	for(i=0;i<g->nv;i++){
		if(f(g->V[i])==f(v1)){
			ins(g->E[i], new);	
			added = 1;
		}
	}		
	if(added != 1){
		g->V = (vert*)realloc(g->V,++g->nv*sizeof(vert));
		g->V[g->nv-1] = v1;
		g->E = (List*)realloc(g->E,g->nv*sizeof(List));
		g->E[g->nv-1] = newlist();
		ins(g->E[g->nv-1], new);	
	}
	for(i=0;i<g->nv;i++){
		if(f(g->V[i])==f(v2)){
			g->ne++;
			return g;
		}
	}

	g->V = (vert*)realloc(g->V,++g->nv*sizeof(vert));
	g->V[g->nv-1] = v2;
	g->E = (List*)realloc(g->E,g->nv*sizeof(List));
	g->E[g->nv-1] = newlist();
	g->ne++;
	return g;
}

int degree(Graph g, vert v){
	int count =0, i;	
	for(i=0;i<g->nv;i++){
		if(f(g->V[i])==f(v)){
			break;
		}
	}
	if(i<g->nv)
		return g->E[i]->length;
	else
		return 0;
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
		printf("%d-> ",g->V[i].val);
		node* current = g->E[i]->head;
		for(j=0;current!=NULL;current=current->next){
			printf("%d ",current->e.val);
		}
		printf("\n");
	}
}
