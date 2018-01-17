#include<stdio.h>
#include<stdlib.h>


typedef struct{} Key;
typedef struct {
	int number;
	Key k;
}Element;


typedef struct Node{
	int e;
	struct Node* next;
}Node;

typedef struct{
	Node* head;
	Node* tail;
	int size; 
}SeqList;

SeqList newList(); // creates an empty list
SeqList insertInOrder(SeqList sl, int e); // add e to sl in order of key assuming sl is ordered; return the modified list
SeqList insertAtFront(SeqList sl, int e); // add e at the front of the list; return the modified list
SeqList insertAtEnd(SeqList sl, int e); // add e at the end of the list; return the modified list
SeqList delete(SeqList sl, int e); // delete e from sl; return the modified list
SeqList deleteAtFront(SeqList sl); // delete the first element from sl; return the modified list 
Element find(SeqList sl, Key k);

SeqList merge(SeqList sl1, SeqList sl2);//merges two sorted lists
SeqList insertionSort(SeqList sl);//sorts an unsorted list and returns the sorted list;

void printList(SeqList sl);
