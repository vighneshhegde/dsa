#include"merge.h"

int main(){
	int n = 5;
	student** arr = createArray(n);
	
	FILE *f = fopen("5.txt", "r");

	readfile(f,arr,n);
	//printArray(arr, n);

//	student** mrg = createArray(n+n);
	
//	merge(arr,n,arr,n,mrg);

	mergeSort(arr, 0, n-1);

	printArray(arr, n);


}
