#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#ifndef ELEMENT

typedef int Key;
typedef struct {
	Key k;
}Element;
#endif

void insertInOrder(Element* Ls, int size);
void insertionSort(Element* Ls, int size);
int compareI(Element a, Element b);
void swapI(Element* a, Element* b);
