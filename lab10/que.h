#include<stdio.h>
#include<stdlib.h>

#ifndef ELEM
#define ELEM
typedef struct {
	int dummy;
}Element;
#endif

typedef enum { false, true } Boolean;

typedef struct qnode{
	Element e;
	struct qnode* next;
}qnode;
  
typedef struct{
	qnode* head;
	qnode* tail;
	int length;
}Queue;

Queue newQ(); // returns an empty Queue
Boolean isEmptyQ(Queue q); // tests whether q is empty
void delQ(Queue* q); // deletes the element from the front of the Queue; returns the modified Queue
Element front(Queue q); // returns the element from the front of the Queue;
void addQ(Queue *q , Element e); // adds e to the rear of the Queue; returns the modified Queue
int lengthQ(Queue q); // returns the length of the Queue

