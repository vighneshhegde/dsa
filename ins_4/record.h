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

record* newRecord();

record** recArray(record** rarr, int n);
void readFile(FILE *f, record** r);
void printRecord(FILE* f,record* r);

void insertInOrderIter(record** r, int size, record* rec);
void insertInOrderRec(record** r, int size, record* rec);
void insertionSort(record** r, int size);
void printList(FILE* f,record* r[], int size);
