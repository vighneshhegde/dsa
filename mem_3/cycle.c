#include"cycle.h"
#include<time.h>


list* createList(int n){
	list* ls = (list*)myalloc(sizeof(list));
	ls->head = NULL;
	ls->tail = NULL;
	ls->length = 0;
	srand(time(NULL));
	int i;
	if(n>=1){
		ls->head = (node*)myalloc(sizeof(node));
		ls->head->e = rand()%100;
		ls->tail = ls->head;
		ls->tail->next = NULL;
		ls->length++;
	}
	node* current = ls->head;
	for(i=1;i<n;i++)
	{
		current->next = (node*)myalloc(sizeof(node));
		current->next->e=rand()%100;
		current=current->next;
		ls->length++;
		ls->tail = current;
		ls->tail->next = NULL;
	}
	return ls;
}

void createCycle(list* ls){
	
	srand(time(NULL));
	if(rand()%2){
		node* current = ls->head;
		int r = rand()%100;
		while(current->e != r){
			current= current->next;
		}
		ls->tail->next = current;
	}
}

//bool isSameNode(node* n1, node* n2)

node** advance(node** current){
	if(*current!=NULL)
		*current = (*current)->next;
	return current;
}
void advanceAll(node** a, node** b, node** c){
	if((*c)!=NULL){
		*a = *b;
		*b = *c;
		*c = (*c)->next;
	}
}

bool testCyclic(list* ls){
	node *hare, *tort;
	hare = ls->head;
	tort = ls->head;
	while(hare != NULL){
		advance(advance(&hare));
		advance(&tort);
		if(hare == tort) return TRUE;
	}
	return FALSE;
}

bool linkRev(list* ls){
	if(ls->length<3) return FALSE;
	node *a,*b,*c;
	a = ls->head;
	b = a->next;
	c = b->next;
	
	a->next = NULL;

	while(c!=NULL){
		b->next = a;
	//	printf("%d ",b->e);
		advanceAll(&a,&b,&c);
	}

	if(b==ls->head) return TRUE;
	else return FALSE;
	
}

void printList(list* ls){
	int flag = 0,i;
	node* current = ls->head;
	for(i =0;i<ls->length;i++){
		printf("%d ", current->e);
		current=current->next;
	}
	if(current!=NULL) printf("and so on...");
	printf("\n");
}

void makeCircular(list* ls){
	if(ls->length ==0) return;
	if(!testCyclic(ls)){
		ls->tail->next = ls->head;
		return;
	}
	node *temp;
	node *newhead = ls->tail->next;
	while(ls->head!=newhead){
		temp = ls->head;
		ls->head = ls->head->next;
		myfree(temp);
	}

}
