#include"que.h"
//assume element is int

void traverse(Queue q){
	node* current = q.head;
	while(current!=NULL){
		//printf("%d ", current->e);
		printf("%d ",current->e);
		current = current->next;
	}
	printf("\n");
}

int main(){
	Queue q = newQ();
	
	addQ(&q, 1);
	addQ(&q, 2);
	addQ(&q, 3);
	addQ(&q, 4);
	addQ(&q, 5);


	traverse(q);	
	return 0;
}
