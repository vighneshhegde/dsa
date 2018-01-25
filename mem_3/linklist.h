#include<stdio.h>

#ifndef ELEMENT
typedef int Element;
#endif

typedef struct node{
	Element e;
	struce node* next;
}node;

typedef struct{
	node* head;
	int size;
}list;


