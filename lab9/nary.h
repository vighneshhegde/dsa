#define ARRAY

#define ELEMENT
typedef struct ntree* Element;

#include"iter.h"

#define ELEM
typedef struct iter* Elem;
typedef Elem Iterator;
#include"set.h"

typedef struct ntree {
	int val;
	Iterator it;
}ntree;


typedef struct ntree* Tree;

Tree createTree(int chilNo, int maxh);

bool isEmptyTree(Tree t);

int getRootVal(Tree t);

Iterator getChildren(Tree t);
	

