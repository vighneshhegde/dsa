#include"mque.h"
#include<ctype.h>
#include<sys/time.h>
#include<unistd.h>

int extractNumber(char* str){//to extract inputsize. Unnecessary, but was fun
	int i=0,j=0;
	char tmp[10];
	for(i=0;str[i];i++){
		if(isdigit(str[i])){
			tmp[j] = str[i];
			j++;	
		}
	}
	tmp[j] = '\0';
	//printf("%s",tmp);
	return atoi(tmp);
}

MultiQ loadFile(FILE *f){
	MultiQ mq = createMQ(10);
	int i;
	Task tmp = newTask(0,0);
	while(fscanf(f,"%ld,%d",&tmp.tid,&tmp.p)!=EOF){
		addMQ(&mq, tmp);
	}
//	printf("%d", isEmptyMQ(mq));	
	return mq;
}

void testDel(MultiQ* mq, int num){
	int i;
	for(i=0;i<num;i++){
		delNextMQ(mq);
	}
}

int main(int argc, char** argv){//input file given as command line argument

//	struct timeval t1, t2;
//	double elapsedTime;
	FILE *f = fopen( argv[1],"r");
//	int size = extractNumber(argv[1]);
	//printMQ(mq);
// start timer
//gettimeofday(&t1, NULL);
	MultiQ mq = loadFile(f);
// stop timer
//gettimeofday(&t2, NULL);
	printMQ(mq);
	//sleep(10);
	delNextMQ(&mq);
	testDel(&mq,50);
	printMQ(mq);

// compute and print the elapsed time in millisec
//elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
//elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
//printf("Total time is %f ms.\n",elapsedTime);









	return 0;
}
