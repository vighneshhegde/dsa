#include"mque.h"


void traverse(Queue q){
	node* current = q.head;
	while(current!=NULL){
		//printf("%d ", current->e);
		printTaskID(current->e);
		current = current->next;
	}
	printf("\n");
}


void printTask(Task t){
	printf("%ld, %d\n", t.tid,t.p);
}

void printTaskID(Task t){
	printf("%ld ", t.tid);
}
void printMQ(MultiQ mq){
	int i=0;
	for(i=0;i<mq.num; i++){
		printf("%d. ",i+1);
		traverse(mq.qs[i]);
	}
}
MultiQ createMQ(int num){
	MultiQ* mq = (MultiQ*)malloc(sizeof(MultiQ)); 
	mq->qs = (Queue*)malloc(num*sizeof(Queue));
	int i;
	for (i=0;i<num;i++) mq->qs[i] = newQ();
	mq->num = num;
	return *mq;

}
void addMQ(MultiQ* mq, Task t) {
	addQ(mq->qs+(t.p-1), t);//ith index of the array has i+1th priority
		
}
Task nextMQ(MultiQ mq){
	int i;
	for(i=0;i<mq.num;i++){
		if(!isEmptyQ(mq.qs[i]))
		{
			return front(mq.qs[i]);	
		}
	}
	return newTask(-1,-1);
}

Task newTask(TaskID id, Priority p){//empty task
	Task* t = (Task*)malloc(sizeof(Task));
	t->tid = id;
	t->p = p;
	return *t; 
}
void delNextMQ(MultiQ* mq){
	int i;
	if(isEmptyMQ(*mq)){
		printf("Cannot delete from an empty queue.");
		return;
	}
	for(i=0;i<mq->num;i++){
		if(!isEmptyQ(mq->qs[i]))
		{
			delQ(mq->qs+i);
			return;
		}
	}
	
}
Boolean isEmptyMQ(MultiQ mq) {
	int i;
	for(i=0;i<mq.num;i++){
		if(!isEmptyQ(mq.qs[i]))
		{
			return false;
		}
	}
	return true;
}
int sizeMQ(MultiQ mq) {
	int i, size=0;
	for(i =0; i<mq.num; i++){
		size += lengthQ(mq.qs[i]);
	}
	return size;
}
int sizeMQbyPriority(MultiQ mq, Priority p){
	return lengthQ(mq.qs[p-1]);
}
Queue getQueueFromMQ(MultiQ mq, Priority p){
	return (mq.qs[p-1]);
}

