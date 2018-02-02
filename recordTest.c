#include"record.h"

int main(int argc, char** argv){
	FILE *f = fopen("10","r");
	int n = 10;//atoi(argv[1]);
	record** r = recArray(NULL,n);
	int i;
	for(i=0;i<n;i++){
		r[i] = newRecord();
	}

//	record* r = newRecord();
//	fscanf(f,"\"%lu,%s,%d/%d,%s,%s\"",&r->cnum,r->bcode,&r->exp.month,&r->exp.year,r->fname,r->lname);
	
	readFile(f, r);
	fclose(f);
	for(i=0;i<n;i++){
		printRecord(r[i]);
	}
	record* r1 = newRecord();
	r1 = r[3];
	insertInOrder(r,10,r1);
//	for(i=0;i<n+1;i++){
//		printRecord(r[i]);
//	}

}
