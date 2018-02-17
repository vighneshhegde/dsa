#include"merge.h"
#include<sys/time.h>


int main(){
	struct timeval t1,t2;
	double time;

	int n = 10240;
	student** arr = createArray(n);
	
	FILE *f = fopen("10240.txt", "r");

	readfile(f,arr,n);

//	student** mrg = createArray(n+n);
	
//	merge(arr,n,arr,n,mrg);
	gettimeofday(&t1, NULL);
	
	mergeSortIter(arr, 0, n-1);
	
	gettimeofday(&t2, NULL);

	time = (t2.tv_sec - t1.tv_sec)*1000;
	time += (t2.tv_usec - t1.tv_usec)/1000;
	printf("The time taken by iterative mergesort is %f ms\n",time);
//	printArray(arr, n);


}
