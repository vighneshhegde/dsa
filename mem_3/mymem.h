#include<stdlib.h>
#include<stdio.h>

size_t total_mem;

void printMem();

void* myalloc(size_t size);

void myfree(void * ptr);
