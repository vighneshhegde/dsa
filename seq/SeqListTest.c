#include"SeqList.h"

//how do you test

int main(int argc, char** argv)
{
	SeqList sl = newList();
	sl = insertAtEnd(sl,4);
	sl = insertAtFront(sl,7);
	sl = insertInOrder(sl,9);
	sl = insertInOrder(sl,1);
	sl = insertInOrder(sl, 6);
	sl = insertionSort(sl);
//	sl = delete(sl, 4);
	printList(sl);

	SeqList sl2 = newList();
	sl2 = insertAtEnd(sl2,5);
	sl2 = insertAtFront(sl2,2);
	sl2 = insertAtFront(sl2,0);
	sl = merge(sl, sl2);
	printList(sl);
	return 0;
}

