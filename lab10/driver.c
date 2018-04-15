#define ADJLIST
#include"graph.h"
#include"que.h"
int main(int argc, char** argv){
	vert v1;
	v1.val = atoi(argv[1]); 
	FILE* f = fopen("graph0.txt","r");
	Graph g = readFile(f);
	//printg(g);
	//addEdge(g, v1,v2);
	//printg(g);
	//addEdge(g, v1,v1);
	//addEdge(g, v3,v2);
	//printf("%d\n", degree(g,v3));
	//vert* v = getAdjacent(g,v2);
//	vert* v = getAdjacent(g,v1);
//	printf("%d %d %d", v[0].val, v[1].val,v[2].val);
//	printg(g);

	printf("%d\n",bfs(g,v1));
}
