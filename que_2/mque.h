#include"que.h"


typedef long int TaskID;
typedef int Priority;

typedef struct{
	TaskID tid;
	Priority p;
}Task;

typedef Task Element; 
 
typedef Queue* MultiQ;

MultiQ createMQ(int num); // creates a list of num Queues, each of which is empty.
void addMQ(MultiQ* mq, Task t); // adds t to the Queue corresponding to priority p in mq. Task includes a TaskID tid and a priority p.
Task nextMQ(MultiQ mq); // returns the front of the non-empty Queue in mq with the highest priority.
Task delNextMQ(MultiQ mq); // deletes the front of the non-empty Queue in mq with the highest priority; returns the modified MultiQ
Task isEmptyMQ(MultiQ mq); // tests whether all the Queues in mq are empty
int sizeMQ(MultiQ mq); // returns the total number of items in the MultiQ
int sizeMQbyPriority(MultiQ mq, Priority p);// returns the number of items in mq with the priority p.
Queue getQueueFromMQ(MultiQ, Priority p);// returns the Queue with priority p.




void traverse(Queue q);//prints queue in order
void printTask(Task t);//print task
