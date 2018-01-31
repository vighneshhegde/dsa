#include<stdio.h>
#define ELEMENT
typedef int Element;

#include"linklist.h"
#include"mymem.h"

typedef enum{FALSE, TRUE} bool;

list* createList(int n);
void createCycle(list* ls);
bool testCyclic(list* ls);
bool linkRev(list* ls);
node** advance(node** current);
void advanceAll(node** a, node** b, node** c);
void makeCircular(list* ls);

void printList(list* ls);

