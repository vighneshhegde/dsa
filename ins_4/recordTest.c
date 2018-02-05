#include"record.h"
#include<sys/time.h>

int main(int argc, char** argv){
	struct timeval t1, t2;
	double elapsedTime;	

	FILE *f = fopen(argv[1],"r");
	int n = atoi(argv[1]);
	record** r = recArray(NULL,n);
	int i;
	for(i=0;i<n;i++){
		r[i] = newRecord();
	}

//	record* r = newRecord();
//	fscanf(f,"\"%lu,%s,%d/%d,%s,%s\"",&r->cnum,r->bcode,&r->exp.month,&r->exp.year,r->fname,r->lname);
	
	readFile(f, r);
	fclose(f);
	// start timer
	gettimeofday(&t1, NULL);
	// do something or call a function
	// ...

	insertionSort(r,n);
	
	
	// stop timer
	gettimeofday(&t2, NULL);
	// compute and print the elapsed time in millisec
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time is %f ms.\n", elapsedTime);
	// sec to ms
	// us to ms
	FILE  *f2 = fopen(argv[2],"w");
	printList(f2, r, n);
	fclose(f2);
}
