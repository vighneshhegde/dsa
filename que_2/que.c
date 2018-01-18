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
	if(q.length==0){
		printf("can't delete from an empty queue\n");
		return q;
	}
	//free memory??
	if(q.length==1){
		return newQ();
	}
	q.head = q.head->next;
	q.length--;
	return q;
}

Element front(Queue q){
	return q.head->e;
}

Queue addQ(Queue q, Element e){//add in the end using the tail
	node* new = (node*)malloc(sizeof(node));
	new->e = e;
	new->next = NULL;
	if(isEmptyQ(q)){
		q.head = new;
//		printf("%d", e);
//		printf("empty\n");
		q.tail = new;
		q.length++;
		return q;
	}

	q.tail->next = new;
	q.tail = q.tail->next;
	q.length++;
	return q;
}

int lengthQ(Queue q){
	return q.length;
}





