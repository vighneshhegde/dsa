#include"avl.h"

int main(int argc, char* argv[]){
	BTree* bt = createTree();
	add(bt, 10);
	add(bt, 11);
	add(bt, 9);
	printI(bt->root);
}
