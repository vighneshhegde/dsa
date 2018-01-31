#include<stdio.h>
#include<stdlib.h>

#ifndef ELEMENT
typedef struct{
	int e;
}Element;
#endif

typedef struct node{
	Element e;
	struct node* next;
}node;

typedef struct{
	node* head;
	node* tail;
	int length;
}list;


