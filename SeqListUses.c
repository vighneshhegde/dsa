#include"SeqList.h"

SeqList merge(SeqList sl1, SeqList sl2)//merges two sorted lists
{
	while(sl2.head!=NULL){
		sl1 = insertInOrder(sl1, sl2.head->e);
		sl2 = deleteAtFront(sl2);
	}
	return sl1;
}


SeqList insertionSort(SeqList sl)//sorts an unsorted list and returns the sorted list;
{
	SeqList sl2 = newList();
	while(sl.head!=NULL){
		sl2 = insertInOrder(sl2, sl.head->e);
		sl = deleteAtFront(sl);
	}
	return sl2;
}
