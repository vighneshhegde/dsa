#include"avl.h"

int main(int argc, char* argv[]){
	BTree* bt = createTree();
	add(bt, 10);
	add(bt, 11);
	add(bt, 12);
	add(bt, 13);
	add(bt, 9);
	
//	printI(bt->root);
	node* nd = find(bt, 8);
	printI(nd);
	delete(bt, 9);
	
	printI(bt->root);
}
