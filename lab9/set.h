#include<stdio.h>
#include<stdlib.h>

//allows only LL implementation of stack and queue

#ifndef ELEM
#define ELEM
typedef struct elem* Elem;
#endif

#ifndef SET
#define SET
typedef struct set* Set;
#endif

typedef struct node{
	Elem e;
	struct node* next;
}node;
  
typedef struct set{
	node* head;
	node* tail;
	int length;
}set;


Set newSet();


void push(Set s, Elem e);
Elem top(Set s);
Elem pop(Set s);
