#define ARRAY
#include"iter.h"

Iterator createIter(int n){
	Iterator it = (Iterator)malloc(sizeof(iter));
	it->arr = (Element*)calloc(n,sizeof(Element));
	it->index = 0;
	it->size = n;
	return it;
}

void insert(Iterator it, Element e){
	it->arr[it->index] = e;
	it->index++;
}

bool hasNext(Iterator it){
	if((it->index+1) == it->size) return false;
	else return true;
}

Element getNext(Iterator it){
	if(hasNext(it)){
		return it->arr[it->index++];
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
