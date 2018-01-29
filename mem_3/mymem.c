#include"mymem.h"

size_t total_mem = 0;

void* myalloc(size_t size){
	total_mem+= size;
	void* mem = malloc(size+sizeof(size_t));
	if(mem== NULL) return mem;
	*(size_t*)mem = size;
	return (mem+sizeof(size_t));

}

void myfree(void * ptr){
	total_mem-= *(size_t*)(ptr - sizeof(size_t)); 
	free(ptr-sizeof(size_t));
//	free(ptr);
}
