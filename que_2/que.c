#include"que.h"



Queue newQ(){
	Queue* new = (Queue*)malloc(sizeof(Queue));
	new->head = NULL;
	new->tail = NULL;
	new->length = 0;
	return *new;
}

Boolean isEmptyQ(Queue q){
	if (q.length ==0){
		return true;}
	else{return false;}
}

Queue delQ(Queue q){
	q.head = q.head->next;
	
	//free memory??
	q.length--;
	return q;
}

Element front(Queue q){
	return q.head->e;
}

Queue addQ(Queue q, Element e){
	node* new = (node*)malloc(sizeof(node));
	new->e = e;
	new->next = NULL;
	q.tail->next = new;
	q.tail = next;
	q.length++;
	return q;
}

int lengthQ(Queue q){
	return q.length;
}

void traverse(Queue q){
	node* current = q.head;
	while(current->next!=NULL){
		printf("%d ", current->e);
		current = current->next;
	}
	printf("\n");
}







