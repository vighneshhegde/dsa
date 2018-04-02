#include"nary.h"

int main(){
	srand(8);
	Tree t = createTree(5);
	int i;
	Element temp;
	for(i=0;i<5;i++){
		t->it[i] = createTree(9);
		printf("%d ", getRootVal(t->it[i]));
	}
	printf("\n");
	Iterator nit = getChildren(t);
	for(i=0;i<5;i++){
		printf("%d ", getRootVal(getNext(&nit)));
	}

	printf("%d ",getRootVal(t));
	return 0;
}
