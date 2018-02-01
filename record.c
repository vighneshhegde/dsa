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
	//fgetc();
//	printf("%s",r[i]->bcode);

//	printRecord(r[i]);
	}

//	while(fscanf(f,"\"%lu,%[^,],%d/%d,%[^,],%[^\"]\"\n",&r[i]->cnum,r[i]->bcode,&r[i]->exp.month,&r[i]->exp.year,r[i]->fname,r[i]->lname)){
//		i++;	
//	}
}

void printRecord(record* r){
	printf("\"%lu,%s,%d/%d,%s,%s\"\n",r->cnum,r->bcode,r->exp.month,r->exp.year,r->fname,r->lname);
}

void insertInOrder(record** r, int size, record* rec){

	r = (record**)realloc(r,(size+1)*sizeof(record*));
	int i;
//	r[size+1]=r[size];
	printf("%ld\n",rec->cnum);
	printf("%ld\n",r[size-1]->cnum);
//	for(i=size;rec->cnum<=r[i]->cnum;i--) {
	for(i=size+1;rec->cnum<=r[i]->cnum;i--) {
		*r[i]=*r[i-1];
	}
	printf("%ld\n",rec->cnum);
	r[i] = rec;
}
