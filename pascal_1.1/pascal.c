#include"pascal.h"

int* createLine(int n)
{
	return (int*)malloc(n*sizeof(int));
}

int** createTriangle(int n){
	int i;
	int **tr = (int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		tr[i] = createLine(i+1);
	}
	return tr;
}

long int f(int n){
	if(n==0)
		return 1;
	else
		return n*f(n-1);
}

int nCr(int n, int r){
	return (f(n)/(f(n-r)*f(r)));
}

int* fillLine(int* line, int n){
	int i;
	for(i=0; i<=n; i++){
		line[i] = nCr(n,i);
	}
	return line;	
}

int** fillTriangle(int** tr, int n){
	int i,j;
	for(i=0; i<n; i++){
		tr[i] = fillLine(tr[i],i);
	}
	return tr;
}

void printKthLine(int* line, int k, int n){
	int i;
	for(i=0; i<n-k-1; i++)
		printf("  ");
	for(i=0; i<k+1; i++)
		printf("%d   ", line[i]);
	printf("\n");
}

void printTr(int** tr, int n){
	int i;
	for(i=0; i<n; i++)
		printKthLine(tr[i], i, n);
}
















