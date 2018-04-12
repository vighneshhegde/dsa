#include"besthash.h"
#define ELEMENT
typedef struct {
	int in;
	int cnt;
}Element;


#include"linklist.h"

typedef struct {
	list** tab;
	int elcnt;
	int icost;
	int qcost;
}hashT;

typedef hashT* HashT;

HashT createHT(int tsize);
int insHT(HashT ht, char** book, int ind);
int insAll(HashT ht, char** book, int imax);//return icost
Element lookup(HashT ht, char** book, char* str);
int lookupAll();//return qcost

void printHT(HashT ht);
void printE(Element e);
