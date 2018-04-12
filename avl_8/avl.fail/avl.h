#include<stdio.h>
#include<stdlib.h>

#ifndef ELEMENT
#define ELEMENT

typedef int Key;
typedef int Element;

#endif

typedef struct node
{
	Element val;
	struct node *left;
	struct node *right;
	int bal;//:2;

}node;

typedef struct {
	node* root;
	int height;
}BTree;

int rgen();


BTree* createTree();
node* createNode(Element e);
int add(BTree* bt, Key k);
node* find(BTree* bt, Key k);
void delete(BTree* bt, Key k);
node* inOrderDel(node* nd);

void addNode(node* root, node* new);
void printI(node* nd);


