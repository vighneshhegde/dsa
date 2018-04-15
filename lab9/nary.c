#include"nary.h"

Tree createTree(int chilNo, int maxh){
	Tree t = (Tree)malloc(sizeof(ntree));
	t->val = rand()%10;
	t->it = createIter(chilNo);
	int i;
	if(maxh==0) return NULL;	
	for(i=0;i<chilNo; i++){
		insert(t->it, createTree(chilNo, maxh-1));
		printf("%d ",t->it->index);
	}
}

bool isEmptyTree(Tree t){
	if(t==NULL) return true;
	return false;
}

int getRootVal(Tree t){
	return t->val;	
}

Iterator getChildren(Tree t){
	return t->it;
}
