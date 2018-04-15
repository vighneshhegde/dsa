#include"set.h"

Set newSet(){
	Set new = (Set)malloc(sizeof(set));
	new->head = NULL;
	new->tail = NULL;
	new->length = 0;
	return new;
}


Element pop(Set s){
	if(s->length==0){
		printf("can't delete from an empty queue\n");
		return NULL;
	}
	Element e = s->head->e;
	else if(s->length==1){
		s = newQ();
	}
	else{
		s->head = s->head->next;
		s->length--;
	}
	return e;
}

Element top(Set s){
	return s.head->e;
}

void push(Set s, Element e){//add in the end using the tail
	node* new = (node*)malloc(sizeof(node));
	new->e = e;
	new->next = NULL;
	if(s->length==0){
		s->head = new;
		s->tail = new;
		s->length++;
	}
	else{
		s->tail->next = new;
		s->tail = s->tail->next;
		s->length++;
	}
}






