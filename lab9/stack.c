#include"set.h"

Set newSet(){
	Set new = (Set)malloc(sizeof(set));
	new->head = NULL;
	new->tail = NULL;
	new->length = 0;
	return new;
}


Elem pop(Set s){
	if(s->length==0){
		printf("can't delete from an empty queue\n");
		return NULL;
	}
	Elem e = s->head->e;
	if(s->length==1){
		s = newSet();
	}
	else{
		s->head = s->head->next;
		s->length--;
	}
	return e;
}

Elem top(Set s){
	return s->head->e;
}

void push(Set s, Elem e){//add in the front using head
	node* new = (node*)malloc(sizeof(node));
	new->e = e;
	new->next = NULL;
	if(s->length==0){
		s->head = new;
		s->tail = new;
		s->length++;
	}
	else{
		new->next = s->head;
		s->head = new;
		s->length++;
	}
}






