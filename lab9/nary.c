#include"nary.h"

Tree createTree(int chilNo){
	Tree t = (Tree)malloc(sizeof(node));
	t->val = rand()%10;
	t->it = (Iterator)malloc(chilNo*sizeof(Tree));
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
