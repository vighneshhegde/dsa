#include<stdio.h>
#include<stdlib.h>

int* createArray(int n);
void printArray(int* arr, int n);
void quicksort(int* Ls, int st, int en);
void swap(int* a, int *b);
int partition(int* Ls, int st, int en, int p);
int partitionLoc(int* Ls, int st, int en, int p);

