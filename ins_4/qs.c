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
void quicksort(record** Ls, int st, int en){
	if(st<en){
		int p = st+rand()%(en-st);// pivot(st, en);
		p =  partitionLoc(Ls, st, en, p);
		quicksort(Ls, st, p-1);
		quicksort(Ls, p+1, en);
	}

}

void swap(record** a, record **b){
	record* temp = *a;
	*a = *b;
	*b = temp;
}

int partition(record** Ls, int st, int en, int p){
	long int k = Ls[p]->cnum;
	swap(&Ls[p], &Ls[st]);
	int lsn = st+1, rsn = en;
	while(lsn<rsn){
		while(Ls[lsn]->cnum<=k && lsn<rsn) lsn++;
		while(Ls[rsn]->cnum>=k && lsn<rsn) rsn--;
		swap(&Ls[lsn], &Ls[rsn]);
	}
	if(lsn>rsn)lsn--;
	if(Ls[lsn]->cnum>=k)
		p = lsn -1;
	else
		p = lsn;

	swap(&Ls[st], &Ls[p]);
	return p;
}
int partitionLoc(record** Ls, int st, int en, int p){
	long int k = Ls[p]->cnum;
	//printf("%d,%d\n",p,k);
	swap(&Ls[p], &Ls[st]);
	int md = st, bdry = st+1;
	while(bdry<=en){
		if(Ls[bdry]->cnum>k){bdry++;}
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
