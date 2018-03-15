#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef enum{FALSE, TRUE} bool;

int hash(char* string, int bnum, int tsize);
int colCount(char** book, int bnum, int tsize);
char** parse(FILE* f);
bool filter(char*);
void profile(char**);
void printbook(char** book);
