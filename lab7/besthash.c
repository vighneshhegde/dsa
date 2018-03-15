#include"besthash.h"

int hash(char* string, int bnum, int tsize){
	long long sum=0;
	int i;
	for(i=0; i<strlen(string); i++){
		sum+=string[i];	
	}
	sum*=1000003;
	return (int)((sum%bnum)%tsize);

}

int colCount(char** book, int bnum, int tsize){
	int* arr = (int*)calloc(tsize,sizeof(int));
	int i, booksize,count = 0;
	char* ptr = book[0];
//	printf("%d",sizeof(book)/sizeof(book[0]));

	for(i=0;i<477;i++){

//	printf("%d ",arr[hash(book[i], bnum, tsize)]);	

		if(arr[hash(book[i],bnum, tsize)]==1){
			count++;
			}
		else
			arr[hash(book[i], bnum, tsize)] = 1;
	}
	return count;
}

char** parse(FILE* f){
	int count = 0;
//	char c;
//	while(c = fgetc(f)!= EOF){
//		if(isspace(c)) count++;
//	}

	char** book = NULL;
	int i,j;
	char* temp= (char*)malloc(100);
	
//	getc(f);

	for(i=0;!feof(f);i++){
		fscanf(f,"%s",temp);
		if(feof(f)) break;
//		printf("%s ", temp);
		if(filter(temp)){
			count++;
			book = (char**)realloc(book,count*sizeof(char*));
			book[count-1] = (char*)malloc(strlen(temp)*sizeof(char));
			strcpy(book[count-1],temp);
		}
	}
	printf("%d ",count);
	return book;
	
}

bool filter(char* str){
	int i;
	for(i=0;i<strlen(str);i++){
		if(!isalpha(str[i]))
			return 0;
	}
	return 1;
}

void printbook(char** book){
	int i;
	for(i = 0; i<30; i++){
		printf("%s ", book[i]);
	}
	printf("\n");
}

