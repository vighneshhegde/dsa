#include<stdio.h>
#include<stdlib.h>

int bits=0;

void p(int pilani){
//int pilani = 0;
printf("%p\n", &pilani);
if(pilani<100)
p(pilani+1);
}
void g(){
int goa = 0;
printf("%p\n", &goa);
}
void h(){
int hyd, ab ;
//printf("%p,%p\n", &hyd, &ab);
int* a = (int*)malloc(8*sizeof(int));
printf("%d,%d", sizeof(a),sizeof(*a));
}
void d(){
int dubai = 0;
printf("%p\n", &dubai);
}
int main(){
//	p(1);
	h();
//	p();
//	g();
//	d();
	printf("\n" );
	return 0;
}

