#include<stdio.h>
#include<stdlib.h>


typedef enum { false, true } Boolean;

typedef long int TaskID;
typedef int Priority;

typedef struct{
	TaskID tid;
	Priority p;
}Task;

typedef Task Element; 

typedef struct node{
	Element e;
	struct node* next;
}node;
  
typedef struct{
	node* head;
	node* tail;
	int length;
}Queue;

Queue newQ(); // returns an empty Queue
Boolean isEmptyQ(Queue q); // tests whether q is empty
void delQ(Queue* q); // deletes the element from the front of the Queue; returns the modified Queue
Element front(Queue q); // returns the element from the front of the Queue;
void addQ(Queue *q , Element e); // adds e to the rear of the Queue; returns the modified Queue
int lengthQ(Queue q); // returns the length of the Queue

