#include"emp.h"

int main(){
	int n = 10;
	FILE* f = fopen("10.txt", "r");
	Element* arr = createArray(n);
//	int i=0;
//	fscanf(f,"%s %ld", arr[i].name, &arr[i].Key);

	readfile(f,arr,n);
	
	printArray(arr, n);
	
//	insertionSort(arr,n);
	quicksortIter(arr, 0, n-1);
//	printArray(arr, n);

	return 0;
}
