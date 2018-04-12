#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"qs.h"

int* createArray(int n){
	int* arr = (int*)malloc(n*sizeof(int));
	int i;
	srand(time(NULL));
	for(i=0; i<n; i++){
		arr[i] = rand()%9;
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
		p =  partitionLoc(Ls, st, en, p);
		//printf("%d\n", &p);
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
int partitionLoc(int Ls[], int st, int en, int p){
	int k = Ls[p];
	//printf("%d,%d\n",p,k);
	swap(&Ls[p], &Ls[st]);
	int md = st, bdry = st+1;//st to md is all elements<k, md+1 to bdry is all >k, and bdry+1 onwards unsorted
	while(bdry<=en){
		if(Ls[bdry]>k){bdry++;}
		else{
			swap(&Ls[bdry], &Ls[md+1]);
			//printf("%d\n",bdry);
			md++;
			bdry++;
		}
	}
	swap(&Ls[st], &Ls[md]);
	return md;	
}
