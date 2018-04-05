#include"graph.h"
#include"que.h"


int bfs(Graph g, vert v){
	if(g->nv<=0)return 0;
	int i;

	Queue q = newQ();

	addQ(&q, v);

	int* visited = (int*)malloc(g->nv*sizeof(int));
	vert root = g->V[0];
	visited[0] = 1; 

	while(!isEmptyQ(q)){
		vert* children = getAdjacent(g, root);
		for(i=0;i<degree(g,root);i++){
			if(f(children[i]) == f(v)) return 1;
			else if(visited[f(children[i])]==1){
				addQ(&q, children[i]);
			}
		}
	root = front(q);
	delQ(&q);
	}
	return 0;
}
