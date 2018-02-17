#include"emp.h"


Element* createArray(int n){
	Element* arr = (Element*)malloc(n*sizeof(Element));
	int i;
	for(i = 0; i<n; i++){
		arr[i].name = (char*)malloc(11*sizeof(char));
	}
	return arr;
}

void readfile(FILE* f,Element* arr, int n){
	int i;
	for(i=0;!feof(f); i++){
		fscanf(f,"%s%ld", arr[i].name, &arr[i].k);
	}
}
void printArray(Element* arr, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%s %ld\n", arr[i].name, arr[i].k);
	}
	printf("\n");
}
