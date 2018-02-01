#include"mymem.h"

size_t total_mem = 0;

void* myalloc(size_t size){
	void* mem = calloc(1,size+sizeof(size_t));
	if(mem== NULL) return mem;
	total_mem += size;
	*(size_t*)mem = size;
	return (mem+sizeof(size_t));

}

void myfree(void * ptr){
	total_mem -= *(size_t*)(ptr - sizeof(size_t)); 
	free(ptr-sizeof(size_t));
//	free(ptr);
}
