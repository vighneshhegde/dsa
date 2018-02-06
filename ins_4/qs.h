#include<stdio.h>
#include"record.h"

int* createArray(int n);
void printArray(int* arr, int n);
void quicksort(record** Ls, int st, int en);
void swap(record** a, record** b);
int partition(record** Ls, int st, int en, int p);

