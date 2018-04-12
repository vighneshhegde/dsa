#include"topo.h"

int main(){
	FILE *f = fopen("graph1.txt", "r");
	Graph g = readFile(f);
	printg(g);

	vert* sorted = topoSort(g);
	int i;
	for(i=0;i<g->nv;i++){
		printf("%d ",sorted[i].val);
	}
}
