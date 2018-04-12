#include"besthash.h"
#include"hasht.h"

int main(){
//	printf("%d", hash("ilovemyindia",401,229));
//	printf("%d", filter("he'llo"));
	int ccount;
	FILE *f = fopen("aliceinwonderland.txt","r");
	char** book = parse(f);
	
//	profile(book);
//	ccount = colCount(book, 104729,50000);
//	printf("%d\n", ccount);
//	printbook(book);
	HashT ht = createHT(50000);

	int count = insAll(ht, book, 22697);
//	printf("%d ",insHT(ht, book, 3));
//	printf("%d ",insHT(ht, book, 3));

	printHT(ht);
	printf("icost: %d\n", count);

	printE(lookup(ht, book, "Project"));

	fclose(f);
}


