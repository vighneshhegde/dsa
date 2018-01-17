#include"SeqList.h"

SeqList newList(){//returns an empty list
	SeqList* new = (SeqList*)malloc(sizeof(SeqList));
	new->head = NULL;
	new->tail = NULL;
	new->size = 0;
	return *new;
}

SeqList insertAtFront(SeqList sl, int e){ // add e at the front of the list; return the modified list
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->e = e;
	if(sl.size ==0){
		newNode->next =NULL;
		sl.head = newNode;
		sl.tail = newNode;
	}
	else{
		newNode->next = sl.head;
		sl.head = newNode;
//		printf("%d",sl.head->next->e);
	}
	sl.size++;
	return sl;	

}
SeqList insertAtEnd(SeqList sl, int e){
	if(sl.size ==0){
		sl = insertAtFront(sl, e);
		return sl;
	}
	else{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->e = e;
		newNode->next = NULL;
		sl.tail->next = newNode;	
		sl.tail = newNode;	
	}
	sl.size++;
	return sl;	
}

SeqList insertInOrder(SeqList sl, int e){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->e = e;
	newNode->next=NULL;
	Node* current=NULL;
	if(sl.head == NULL || newNode->e<sl.head->e){
		sl = insertAtFront(sl, e);
		return sl;
	}
	else{
		current = sl.head;
		while(current->next!=NULL){
			if(current->e<=newNode->e && current->next->e >= newNode->e){
				newNode->next = current->next;
				current->next = newNode;
				break;
				}
			current = current->next;
		}
		if(newNode->next == NULL){
			sl = insertAtEnd(sl,e);
			return sl;
		}
	}
	sl.size++;
	return sl;
}

SeqList delete(SeqList sl, int e){
	Node* current=sl.head;
	while(current->next!=NULL){
		if(current->next->e == e){
			current->next = current->next->next;
			break;
		}
		current = current->next;	
	}
	sl.size--;
	return sl;
}

SeqList deleteAtFront(SeqList sl){
	if(sl.size<1)
		return newList();
	sl.head = sl.head->next;
	return sl;
}

void printList(SeqList sl){
	Node* current=sl.head;
	while(current != NULL){
		printf("%d ", current->e);
		current = current->next;
	}
//	printf(", %d\n", sl.size);
}
	










