#include"cycle.h"

list* createList(int n){
	list* ls = (list*)malloc(sizeof(list));
	ls->head = NULL;
	ls->tail = NULL;
	ls->size = 0;
	node* current = ls->head;
	int i;
	if(n>=1){
		ls->head = (node*)malloc(sizeof(node));
		ls->head->e = rand()%100;
		ls->tail = ls->head;
		ls->tail->next = NULL;
		ls->size++;
	}
	for(i=1;i<n;i++)
	{
		current->next = (node*)malloc(sizeof(node));
		current->next->e=rand()%100;
		current=current->next;
		ls->size++;
		ls->tail = current;
		ls->tail->next = NULL;
	}
	return ls;
}

void createCycle(list* ls){
	
	if(rand()%2){
		node* current = ls->head;
		int r = rand()%100;
		while(current->e != r){
			current= current->next;
		}
		ls->tail->next = current;
	}
}
