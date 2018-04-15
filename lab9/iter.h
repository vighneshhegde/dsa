#include<stdio.h>
#include<stdlib.h>

#ifndef ELEMENT
#define ELEMENT
typedef struct element* Element;
#endif

typedef enum{false,true} bool;

#ifdef ARRAY
typedef struct iter{
	Element* arr;
	int index;
	int size; 
}iter;

typedef iter* Iterator;
#endif

#ifdef LL
#include"linklist.h"
typedef list* Iterator;
#endif

bool hasMore(Iterator it);

Element getNext(Iterator it);

Iterator createIter(int n);

void insert(Iterator it, Element e);
