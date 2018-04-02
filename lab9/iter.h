#include<stdio.h>
#include<stdlib.h>

#ifndef ELEM
#define ELEM
typedef void* Element;
#endif

typedef enum{false,true} bool;

/*
typedef struct{
	Element* arr;
	int index;
	int size; 
}Iterator;

*/

typedef Element* Iterator;

bool hasMore(Iterator it);

Element getNext(Iterator* it);

