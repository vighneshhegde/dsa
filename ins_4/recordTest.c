#include"record.h"

int main(int argc, char** argv){
	FILE *f = fopen("output1","r");
	int n = atoi(argv[1]);
	record** r = recArray(NULL,n);
	int i;
	for(i=0;i<n;i++){
		r[i] = newRecord();
	}

//	record* r = newRecord();
//	fscanf(f,"\"%lu,%s,%d/%d,%s,%s\"",&r->cnum,r->bcode,&r->exp.month,&r->exp.year,r->fname,r->lname);
	
	readFile(f, r);
	fclose(f);
//	for(i=0;i<n;i++){
//		printRecord(r[i]);
//	}
	insertionSort(r,n);
	
	FILE  *f2 = fopen("outpu1","w");
	printList(f2, r, n);
	fclose(f2);
}
