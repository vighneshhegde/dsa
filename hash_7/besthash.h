#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#ifndef BOOL
#define BOOL
typedef enum{FALSE, TRUE} bool;
#endif

int hash(char* string, int bnum, int tsize);
int colCount(char** book, int bnum, int tsize);
char** parse(FILE* f);
bool filter(char*);
void profile(char**);
void printbook(char** book);
