#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//#ifndef Element
//typedef int Element;
//typedef int Key;
//#endif

typedef struct {
	char* name;
	float cgpa;
} student;

student** createArray(int n);
void readfile(FILE *f, student** arr, int n);
void printArray(student** arr, int n);
void copy(student* a, student* b);
int compare(student* a, student* b);
void merge(student** arr1, int sz1, student** arr2, int sz2, student** mrg);
void mergeSortRec(student** arr, int st, int en);
void mergeSortIter(student** arr, int st, int en);
int storeK(FILE* f,int k);
void fprintArray(FILE* f, student** arr, int n);
void mergeFiles(int fi1, int f12);
char* itostr(int n);
