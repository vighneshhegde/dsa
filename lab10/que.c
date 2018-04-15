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

void delQ(Queue* q){
	if(q->length==0){
		printf("can't delete from an empty queue\n");
	}
	//free memory??
	else if(q->length==1){
		*q = newQ();
	}
	else{
		q->head = q->head->next;
		q->length--;
	}
}

Element front(Queue q){
	return q.head->e;
}

void addQ(Queue *q, Element e){//add in the end using the tail
	qnode* new = (qnode*)malloc(sizeof(qnode));
	new->e = e;
	new->next = NULL;
	if(isEmptyQ(*q)){
		q->head = new;
//		printf("%d", e);
//		printf("empty\n");
		q->tail = new;
		q->length++;
	}
	else{
		q->tail->next = new;
		q->tail = q->tail->next;
		q->length++;
	}
}

int lengthQ(Queue q){
	return q.length;
}





