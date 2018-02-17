#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef ELEMENT

typedef int Key;
typedef struct {
	Key k;
}Element;
#endif


Element* createArray(int n);
void printArray(Element* arr, int n);
void quicksort(Element* Ls, int st, int en);
void quicksortIter(Element* Ls, int st, int en);
void swap(Element* a, Element *b);
int partition(Element* Ls, int st, int en, int p);
int partitionLoc(Element* Ls, int st, int en, int p);

