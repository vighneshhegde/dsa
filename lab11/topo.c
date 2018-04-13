#include"topo.h"

Graph markEdges(Graph g,vert* v){
	int i;
	node* current = g->Elist->head;
	for(i=0;i<g->ne; i++){
		if(current->e->visited==0 && current->e->from->val==v->val){
			current->e->visited = 1;
		}
		current = current->next;
	}
	return g;
}

Graph markVert(Graph g, vert* v){
	int i;
	v->visited = 1;
	for(i=0;i<g->nv;i++){
		if(isAdjacent(g,v,&g->V[i])==1){
			g->V[i].indeg--;
		}
	}
}

int isAdjacent(Graph g, vert* a, vert* b){
	int i;
	node* current = g->Elist->head;
	for(i=0;i<g->ne; i++){
		if(current->e->visited==0 && current->e->from->val==a->val && current->e->to->val==b->val){
			return 1;
		}
		current = current->next;
	}
	return 0;
}

vert* topoSort(Graph g){
	int cnt = 0,i;
	vert* sorted = (vert*)calloc(g->nv,sizeof(vert));
	while(cnt<g->nv){
		for(i = 0;i<g->nv;i++){
			if(g->V[i].visited==0 && g->V[i].indeg==0){
				markVert(g, &g->V[i]);
				markEdges(g,&g->V[i]);
				sorted[cnt++]=g->V[i];
			//	printf(".%d ",g->V[i].val);
				continue;
			}
			//	printf(",%d ",g->V[i].val);
		}
	}
		return sorted;	
}
