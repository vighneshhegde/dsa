#include"cycle.h"


int main(int argc, char** argv){
	int n = atoi(argv[1]);
	list* ls = createList(n);
	createCycle(ls);
	printList(ls);
//	printf("%d\n",testCyclic(ls));//1 if true
//	printf("%d\n",linkRev(ls));//1 if true
	
	makeCircular(ls);

	printList(ls);

	printf("%ld\n",total_mem);
	
	return 0;
}
	

