#include"graph.h"
#include"que.h"
int main(){
	vert v1,v2,v3;
	v1.val = 0, v2.val = 1, v3.val = 2;
	Graph g = createGraph(3);
	//printg(g);
	addEdge(g, v1,v2);
	addEdge(g, v1,v1);
	addEdge(g, v3,v2);
	printf("%d\n", degree(g,v3));
//	vert* v = getAdjacent(g,v2);
//	vert* v = getAdjacent(g,v1);
//	printf("%d %d %d", v[0].val, v[1].val,v[2].val);
	
	printg(g);


	printf("%d",bfs(g,v2));
}
