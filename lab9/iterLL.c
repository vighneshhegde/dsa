#define LL
#include"iter.h"

Iterator createIter(int n){
	return newlist();
}

void insert(Iterator it, Element e){
	node* new = (node*)malloc(sizeof(node));
	new->e = *e;
	new->e = (Element*)malloc(sizeof(Element));
	new->next = NULL;
	ins(it, new);

}
bool hasNext(Iterator it){
	return isEmpty(it);
}

Element getNext(Iterator it){
	return del(it);
}
