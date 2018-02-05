#include"qs.h"

int main(){
	int n = 19;
	int* arr = createArray(n);
	printArray(arr,n);
//		printf("h\n");
	quicksort(arr, 0, n-1);
//	swap(&arr[0],&arr[1]);
	printArray(arr,n);
	return 0;
}
