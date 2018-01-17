#include"pascal.h"

int main(int argc, char** argv){
	
	int n = atoi(argv[1]);
	int **tr = createTriangle(n);	
	tr = fillTriangle(tr, n);
	printTr(tr, n);
//	printf("%d", f(13));
	return 0;
}
