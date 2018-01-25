#include"mymem.h"
#include<time.h>

int main(){
	int m=100000;
	int* a;
	srand(time(NULL));
	do{	
		//printf("%lu\n", total_mem);
//		m = 10000+rand()%15000;
		
		a = (int*)myalloc(m*sizeof(int));
		if(a==NULL){
		printf("max memory = %lu",total_mem);
		break;
		}
//		printf("%p, %p, %d, %lu\n", a, (a+m-1), m, total_mem);
		free(a);
		//printf("%d\n", *a);
		m+=10000;
	}while(a!=NULL);
	return 0;	
}

