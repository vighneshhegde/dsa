#include"mymem.h"
#include<time.h>
#include<unistd.h>

int main(){
	int m=1858992000;
	int* a;
	srand(time(NULL));
	do{	
//		printf("%lu\n", total_mem);
//		m = 10000+rand()%15000;
		
		a = (int*)myalloc(m*sizeof(int));
		if(a==NULL){
		printf("max memory = %llu\n",total_mem);
		break;
		}
		printf("%p, %p, %d, %llu\n", a, (a+m-1), m, total_mem);
//		myfree(a);
//		printf("%lu\n", total_mem);
		m+=15000;
	}while(a==NULL);
//	printf("\n%d",sizeof(size_t));
	sleep(10);
	return 0;	
}

