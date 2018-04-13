#include<stdio.h>
#include<stdlib.h>


#ifndef ELEM
#define ELEM
typedef struct element* Element;
#endif

typedef enum{false,true} bool;

#ifdef ARRAY
typedef struct{
	Element* arr;
	int index;
	int size; 
}Iterator;
#endif

#ifdef LL
#include"linklist.h"
typedef list Iterator;
#endif

bool hasMore(Iterator it);

Element getNext(Iterator* it);

