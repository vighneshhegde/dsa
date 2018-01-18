#include"mque.h"


void traverse(Queue q){
	node* current = q.head;
	while(current!=NULL){
		//printf("%d ", current->e);
		printTask(current->e);
		current = current->next;
	}
	printf("\n");
}


void printTask(Task t){
	printf("%ld, %d ", t.tid,t.p);
}
MultiQ createMQ(int num){
	Queue* mq = (Queue*)malloc(num*sizeof(Queue));
	int i;
	for (i=0;i<num;i++) mq[i] = newQ();
	return mq;

}
void addMQ(MultiQ* mq, Task t) {

		
}
Task nextMQ(MultiQ mq){}
Task delNextMQ(MultiQ mq){}
Task isEmptyMQ(MultiQ mq) {}
int sizeMQ(MultiQ mq) {}
int sizeMQbyPriority(MultiQ mq, Priority p){}
Queue getQueueFromMQ(MultiQ, Priority p){}

