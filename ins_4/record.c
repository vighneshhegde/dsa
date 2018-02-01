#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int month;
	int year;
}date;

typedef struct{
	long unsigned int cnum;
	char* bcode;
	date exp;
	char* fname;
	char* lname;
}record;

void readFromFile(FILE* f, record *r){
	int i = 0;
	while(fscanf(f,"\"%lu,%s,%d/%d,%s,%s\"",r[i]->cnum,r[i]->bcode,r[i]->exp->month,r[i]->exp->year,r[i]->fname,r[i]->lname)!=EOF){
		i++;
	}
	
	
}

record newRecord(){
	record *r = (record*)malloc(sizeof(record));
	r->bcode = (char*)malloc(5*sizeof(char));
	r->fname = (char*)malloc(5*sizeof(char));
	r->lname = (char*)malloc(5*sizeof(char));
	
	return *r;
}

record* newArray(int n){
	record *r;
	int i;
	for(i=0;i<n;i++){
		r[i] = newRecord();
	}
}

