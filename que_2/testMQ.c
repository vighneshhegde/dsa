#include"mque.h"
#include<ctype.h>

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

	FILE *f = fopen(argv[1], "r");
//	int size = extractNumber(argv[1]);
	//printMQ(mq);
	MultiQ mq = loadFile(f);
	printf("%d\n",sizeMQ(mq));
	printMQ(mq);
	delNextMQ(&mq);
	testDel(&mq,5);
	printTask(nextMQ(mq));
	return 0;
}
