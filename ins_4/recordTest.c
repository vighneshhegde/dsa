#include<sys/time.h>
#include"qs.h"

int main(int argc, char** argv){
	struct timeval t1, t2, t3;
	double elapsedTime, elapsedTime2;	

	FILE *f = fopen(argv[1],"r");
	int n = atoi(argv[1]);
	record** r = recArray(NULL,n);
	int i;
	for(i=0;i<n;i++){
		r[i] = newRecord();
	}
	
	readFile(f, r);
	fclose(f);
	// start timer
	gettimeofday(&t1, NULL);
	// do something or call a function
	// ...

	insertionSort(r,n);
	
	
	// stop timer
	gettimeofday(&t2, NULL);
	readFile(f,r);
	//restart timer
	gettimeofday(&t2, NULL);

	quicksort(r, 0, n-1);

	gettimeofday(&t3, NULL);


	// compute and print the elapsed time in millisec
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time for insertionsort is %f ms.\n", elapsedTime);
	// sec to ms
	// us to ms
	elapsedTime2 = (t3.tv_sec - t2.tv_sec) * 1000.0;
	elapsedTime2 += (t3.tv_usec - t2.tv_usec) / 1000.0;
	printf("Total time for quicksort is %f ms.\n", elapsedTime2);

//	FILE  *f2 = fopen(argv[2],"w");
//	printList(f2, r, n);
//	fclose(f2);
}
