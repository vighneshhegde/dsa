#include"emp.h"

void insertInOrder(Element* Ls, int size){
	int i;
	for(i=size-1; i>0 && compareI(Ls[i],Ls[i-1]); i--){
		swapI(&Ls[i], &Ls[i-1]);
//		printf("%d %d",i,size);
	}
}

void insertionSort(Element* Ls, int size){
	int i;
	for(i = 0; i<size; i++){
		insertInOrder(Ls, i+1);
	}
}

void swapI(Element* a, Element* b){
/*	Element* temp = (Element*)malloc(sizeof(Element));
	memcpy(temp, a, sizeof(Element));
	memcpy(a, b, sizeof(Element));
	memcpy(b, temp, sizeof(Element));
	
	free(temp);*/
	Element temp = *a;
	*a = *b;
	*b = temp;
}
int compareI(Element a, Element b){
	if(a.k<b.k) return 1;
	else return 0;	
}
