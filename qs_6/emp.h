#include<stdio.h>

#define ELEMENT
typedef long int Key;
typedef struct{
	char* name;
	Key k;
}Element;

typedef long int empID;

//typedef Element empl;

#include"qs.h"
#include"ins.h"


Element* createArray(int n);
void readfile(FILE* f,Element* arr, int n);
void printArray(Element* arr, int n);

