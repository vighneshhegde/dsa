#include"besthash.h"

int main(){
//	printf("%d", hash("ilovemyindia",401,229));
//	printf("%d", filter("he'llo"));
	int ccount;
	FILE *f = fopen("aliceinwonderland1.txt","r");
	char** book = parse(f);

	ccount = colCount(book, 51233,50000);
	printf("%d\n", ccount);
	printbook(book);

	fclose(f);
}


