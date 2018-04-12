#include"record.h"

record* newRecord(){
	record* r = (record*)malloc(sizeof(record));
	r->bcode = (char*)malloc(5*sizeof(char));
	r->fname = (char*)malloc(5*sizeof(char));
	r->lname = (char*)malloc(5*sizeof(char));

	return r;
}
record** recArray(record** rarr, int n){
	rarr = (record**)realloc(rarr,n*sizeof(record*));
}

void readFile(FILE *f, record** r){
	
	int i=0;
	for(i=0;!feof(f);i++){
	fscanf(f,"\"%lu,%[^,],%d/%d,%[^,],%[^\"]\"\n",&r[i]->cnum,r[i]->bcode,&r[i]->exp.month,&r[i]->exp.year,r[i]->fname,r[i]->lname);
//	printf("%s",r[i]->bcode);

//	printRecord(r[i]);
	}

//	while(fscanf(f,"\"%lu,%[^,],%d/%d,%[^,],%[^\"]\"\n",&r[i]->cnum,r[i]->bcode,&r[i]->exp.month,&r[i]->exp.year,r[i]->fname,r[i]->lname)){
//		i++;	
//	}
}

void printRecord(FILE*f,record* r){
	fprintf(f,"\"%lu,%s,%d/%d,%s,%s\"\n",r->cnum,r->bcode,r->exp.month,r->exp.year,r->fname,r->lname);
}

void insertInOrderIter(record** r, int size, record* rec){
//assuming extra space is there in r in the end
	int i;
	for(i=size-1; i>0 && rec->cnum<r[i-1]->cnum; i--) {
		r[i]=r[i-1];
	}
	r[i] = rec;
}
void insertInOrderRec(record** r, int size, record* rec){

//	r = (record**)realloc(r,(size+1)*sizeof(record*));
	if(size==1){
		r[0] = rec;
		return;
	}
	if(r[size-2]->cnum>rec->cnum){
		r[size-1]=r[size-2];
		insertInOrderRec(r,size-1,rec);
	}
	else r[size-1] = rec;
}

void insertionSort(record** r, int size){
	if(size <= 1) return;
	insertionSort(r,size-1);
	record* temp = r[size-1];
	insertInOrderRec(r,size,temp);

}

void printList(FILE *f,record* r[], int size){
	int i;	
	for(i=0;i<size;i++){
		printRecord(f, r[i]);
	}
//	printf("\n");
}
