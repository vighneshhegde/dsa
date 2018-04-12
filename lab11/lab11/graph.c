#include"graph.h"

Graph readFile(FILE* f){
	Graph g = createGraph();
	int v1,v2;
	while(!feof(f)){
		fscanf(f,"%d %d\n",&v1,&v2);
		g = addEdge(g, v1, v2);
	}
	return g;
}


Graph createGraph(){
	Graph g = (Graph)malloc(sizeof(graph));
	g->nv = 0;
	g->ne = 0;
	
	g->V = (vert*) malloc(8*sizeof(vert));
	g->Elist = newlist();

	return g;
}

vert* addV(Graph g, int v){
	int i;
	for(i=0;i<g->nv;i++){
		if(g->V[i].val==v) return (g->V + i);
	}
	//g->V = (vert*)realloc(g->V,(++g->nv)*sizeof(vert)); 
	g->V[g->nv].val = v;
	g->nv++;
	return (g->V + g->nv-1);
}

Graph addEdge(Graph g, int v1, int v2){
	
	edge* new = (edge*)malloc(sizeof(edge));
	new->from = addV(g,v1);
	new->to = addV(g,v2);
	new->to->indeg++;

	node* newnode = (node*)malloc(sizeof(node));
	newnode->e = new;
	newnode->next = NULL;

	ins(g->Elist,newnode);

	g->ne++;
	return g;
}

void printg(Graph g){
	printf("nv = %d, ne = %d\n",g->nv,g->ne);
	printf("Vertices:\n");
	int i,j;
	for(i=0;i<g->nv;i++){printf("%d ", g->V[i].val);}
	printf("\nEdges:\n");
	node* current = g->Elist->head;
	for(i=0;i<g->ne;i++){
		printf("%d %d ",current->e->from->val,current->e->to->val);
		printf("\n");
		current=current->next;
	}
}
/*
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
*/
	
