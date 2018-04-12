#include"emp.h"


Element* createArray(int n);
void printArray(Element* arr, int n);

void quicksort(Element* Ls, int st, int en){
	if(st<en){
		int p = st+rand()%(en-st);// pivot(st, en);
		p =  partition(Ls, st, en, p);
		//printf("%d\n", &p);
		quicksort(Ls, st, p-1);
		quicksort(Ls, p+1, en);
	}

}
void quicksortIter(Element* Ls, int st, int en){
	int stack[en-st+1];
	int top = -1;
	stack[++top] = st;
	stack[++top] = en;
//put cutoff here`

	while(top>=0){
		en = stack[top--];
		st = stack[top--];


		while(st<en){
			int p = st+rand()%(en-st);// pivot(st, en);
			p =  partition(Ls, st, en, p);
			printf("%d\n", p);
		stack[++top] = st;
		stack[++top] = p-1;
			st = p+1;
		}
	}
	printArray(Ls, 10);
	
}

void swap(Element* a, Element* b){
	Element* temp = (Element*)malloc(sizeof(Element));
	memcpy(temp, a, sizeof(Element));
	memcpy(a, b, sizeof(Element));
	memcpy(b, temp, sizeof(Element));
	
	free(temp);
//	Element temp = *a;
//	*a = *b;
//	*b = temp;
}
int compare(Element a, Element b){
	if(a.k<=b.k) return 1;
	else return 0;	
}

int partition(Element* Ls, int st, int en, int p){
	Element k = Ls[p];
	swap(&Ls[p], &Ls[st]);
	int lsn = st+1, rsn = en;
	while(lsn<rsn){
		while(compare(Ls[lsn],k) && lsn<rsn) lsn++;
		while(compare(k,Ls[rsn]) && lsn<rsn) rsn--;
		swap(&Ls[lsn], &Ls[rsn]);
	}
	if(lsn>rsn)lsn--;
	if(compare(k,Ls[lsn]))
		p = lsn -1;
	else
		p = lsn;

	swap(&Ls[st], &Ls[p]);
	return p;
}
/*
int partitionLoc(int Ls[], int st, int en, int p){
	int k = Ls[p];
	//printf("%d,%d\n",p,k);
	swap(&Ls[p], &Ls[st]);
	int md = st, bdry = st+1;
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
}*/
