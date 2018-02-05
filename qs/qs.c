#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"qs.h"

int* createArray(int n){
	int* arr = (int*)malloc(n*sizeof(int));
	int i;
	srand(time(NULL));
	for(i=0; i<n; i++){
		arr[i] = rand()%4;
	}
	return arr;
}
void printArray(int* arr, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void quicksort(int* Ls, int st, int en){
	if(st<en){
		int p = st+rand()%(en-st);// pivot(st, en);
		p =  partition(Ls, st, en, p);
		quicksort(Ls, st, p-1);
		quicksort(Ls, p+1, en);
	}

}

void swap(int* a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* Ls, int st, int en, int p){
	int k = Ls[p];
	swap(&Ls[p], &Ls[st]);
	int lsn = st+1, rsn = en;
	while(lsn<rsn){
		while(Ls[lsn]<=k && lsn<rsn) lsn++;
		while(Ls[rsn]>=k && lsn<rsn) rsn--;
		swap(&Ls[lsn], &Ls[rsn]);
	}
	if(lsn>rsn)lsn--;
	if(Ls[lsn]>=k)
		p = lsn -1;
	else
		p = lsn;

	swap(&Ls[st], &Ls[p]);
	return p;
}
