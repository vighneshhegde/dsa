#include"iterAR.h"

typedef struct {
	int val;
	Iterator it;
}ntree;

/*
#define ELEM
typedef node* Element;
*/


typedef node* Tree;

Tree createTree(int chilNo);

bool isEmptyTree(Tree t);

int getRootVal(Tree t);

Iterator getChildren(Tree t);
	

