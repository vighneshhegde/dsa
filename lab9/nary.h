
typedef struct {
	int val;
	struct node** it;
}node;

#define ELEM
typedef node* Element;

#include"iter.h"


typedef node* Tree;

Tree createTree(int chilNo);

bool isEmptyTree(Tree t);

int getRootVal(Tree t);

Iterator getChildren(Tree t);
	

