#include"topo.h"

int main(){
	FILE *f = fopen("citation1.txt", "r");
	Graph g = readFile(f);
	printg(g);

	//printf("%d", isAdjacent(g, &g->V[0], &g->V[1]));

	vert* sorted = topoSort(g);
	int i;
	for(i=0;i<g->nv;i++){
		printf("%d ",sorted[i].val);
	}
}
