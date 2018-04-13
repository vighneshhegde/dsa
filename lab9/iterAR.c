#define ARRAY
#include"iter.h"

Iterator CreateIter(int n){
	Iterator* it = (Iterator*)malloc(sizeof(Iterator));
	it->arr = (Element*)calloc(n*sizeof(Element));
	it->index = 0;
	it->size = n;
}

bool hasNext(Iterator it){
	if((it.index+1) == it.size) return false;
	else return true;
}

Element getNext(Iterator it){
	if(hasNext(it)){
		return it.arr[it.index++];
	}
	else return NULL;
}

/*
bool hasNext(Iterator it){
	if(it!=NULL) return true;
	else return false;
}

Element getNext(Iterator* it){
	if(hasNext(*it)){
		Element temp = **it;
		*it = *it+sizeof(Element);
		return temp;
	}
	return NULL;
}
*/
