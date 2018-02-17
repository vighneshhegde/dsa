#include"merge.h"

int main(){
	int k = 4;
//	student** arr = createArray(n);
	
	FILE *f = fopen("8.txt", "r");

//	readfile(f,arr,n);
	//printArray(arr, n);

//	student** mrg = createArray(n+n);
	
//	merge(arr,n,arr,n,mrg);

//	mergeSortIter(arr, 0, n-1);
	int nbk = storeK(f, k);

//	printf("%s", itostr(1));
	mergeFiles(0,1);


//	printArray(arr, n);


}
