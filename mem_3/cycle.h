#include<stdio.h>
#define ELEMENT
typedef long int Element;

#include"linklist.h"

typedef enum{FALSE, TRUE} bool;

list* createList(int n);
void createCycle(list* ls);
bool testCyclic(list* ls);

void printList(list* ls){
	int flag = 0;
	node* current = ls->head;
	while(current !NULL 
