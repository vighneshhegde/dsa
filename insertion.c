#include"record.h"

void insertInOrder(record** r, int size, record* rec){

	r = (record**)realloc(r,(size+1)*sizeof(record*));
	int i;
	r[size]=r[size-1];
	for(i=size-1;rec->cnum<=r[i]->cnum;i--) {
		r[i]=r[i-1];
	}
	r[i] = rec;
}
