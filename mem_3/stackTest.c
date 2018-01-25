#include<stdio.h>

int bits=0;

void p(int pilani){
//int pilani = 0;
printf("%u\n", &pilani);
if(pilani<100)
p(pilani+1);
}
void g(){
int goa = 0;
printf("%u\n", &goa);
}
void h(){
int hyd = 0;
printf("%u\n", &hyd);
}
void d(){
int dubai = 0;
printf("%u\n", &dubai);
}
int main(){
	p(1);
//	h();
//	p();
//	g();
//	d();
	printf("%u\n", &bits);
	return 0;
}

