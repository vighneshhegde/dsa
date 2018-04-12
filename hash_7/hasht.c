#include"hasht.h"


HashT createHT(int tsize){
	HashT ht = (HashT)calloc(tsize,sizeof(hashT));
	ht->tab = (list**)calloc(tsize,sizeof(list*));
	int i;
	for(i=0;i<tsize; i++){
		ht->tab[i] = newlist();
	}
	return ht;
}

int insHT(HashT ht, char** book, int ind){
	char* word = book[ind];
	int h = hash(word, 104729,50000);
	ht->elcnt++;
	//find
	node* current = ht->tab[h]->head;
	int i;
	for(i=0;i<ht->tab[h]->length;i++){
//	printf(" %s,%s ", book[current->e.in], word);
		if(!strcmp(book[current->e.in],word)){
//			printf("a%d",current->e.cnt);
			current->e.cnt++;
			return ht->icost;
		}
		current = current->next;
	}//end find

	node* new = (node*)malloc(sizeof(node));
	new->e.in = ind;
	new->e.cnt = 1;

	ins(ht->tab[h], new);
	return ++ht->icost;
}

int insAll(HashT ht, char** book, int imax){
	int cost = 0, i;
	for(i=0;i<imax;i++){
		cost=insHT(ht, book, i);
	}
	return cost;
}

Element lookup(HashT ht, char** book, char* str){
	int h = hash(str, 104729,50000);
	node* current = ht->tab[h]->head;
	int i;
	for(i=0;i<ht->tab[h]->length;i++){
		if(!strcmp(book[current->e.in],str)){
			
			return current->e;
		}
		current = current->next;
		ht->qcost++;
	}//end find
	Element a;
	return a;
}

void printHT(HashT ht){
	int i,j;

	for (i=0;i<50000;i++){
		if(!isEmpty(ht->tab[i])){
			node* current = ht->tab[i]->head;
//			printf("%d",ht->tab[i]->length);
			for(j=0;/*j<ht->tab[i]->length &&*/ current!=NULL;j++){
				printf("%d. in = %d, cnt = %d \n",i,current->e.in,current->e.cnt);
				current= current->next;
			}
		}
	//	else printf("0 0\n");

	}
}
void printE(Element e){
	printf("{in = %d, cnt = %d}\n", e.in, e.cnt);
}
