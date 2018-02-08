#include"qs.h"

int main(int argc, char** argv){
	if(argc<2){ printf("args pls\n"); return 0;} 
	int n = atoi(argv[1]);
	int* arr = createArray(n);
	printArray(arr,n);
//		printf("h\n");
	quicksort(arr, 0, n-1);
//	swap(&arr[0],&arr[1]);
	printArray(arr,n);
//	quicksort(arr, 0, n-1);
//	printArray(arr,n);
	return 0;
}
