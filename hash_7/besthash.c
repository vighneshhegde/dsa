#include"besthash.h"
#include<math.h>

int hash(char* string, int bnum, int tsize){
	unsigned long long sum=0;
	int i;
	for(i=0; i<strlen(string); i++){
		sum+=(string[i]*(int)pow(10,i));	
	}
//	sum*=1000003;
	return (int)((sum%bnum)%tsize);

}

int colCount(char** book, int bnum, int tsize){
	int* arr = (int*)calloc(tsize,sizeof(int));
	int i, booksize,count = 0;
	char* ptr = book[0];
//	printf("%d",sizeof(book)/sizeof(book[0]));

	for(i=0;i<22698;i++){

//	printf("%d  ",hash(book[i], bnum, tsize));//,arr[hash(book[i], bnum, tsize)]);	

		if(arr[hash(book[i],bnum, tsize)]==1){
			count++;
			}
		else
			arr[hash(book[i], bnum, tsize)] = 1;
	}
	
	printf("%d %d : %d\n",bnum,tsize,count);
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
	
	for(i=0;i<3;i++)getc(f);//otherwise 'Project' won't come, for some reason

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
//	printf("%d ",count);
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

void profile(char** book){
	int c,i,j,minc=999999;
	int primes[] = {5119,6869,8069,10069,11003,17737,50033,73771,96979,100043,104729,103483};
	int sizes[] = {5000,50000};
	for(i=0;i<2;i++){
		for(j=0;j<12;j++){
			c = colCount(book, primes[j], sizes[i]);
			if(c<minc) minc=c;
		}
	}
	printf("Min ColCount = %d\n",minc);
}

void printbook(char** book){
	int i;
	for(i = 0; i<22698; i++){
		printf("%d: %s\n",i, book[i]);
	}
	printf("\n");
}

