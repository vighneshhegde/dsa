#include"avl.h"


int rgen(){
	return(rand()%150 + 150);
}


BTree* createTree(){
	BTree *bt = (BTree*)malloc(sizeof(BTree));
//	bt->root = (node*)malloc(sizeof(node));
	bt->height = 0; 
	return bt;
}

node* createNode(Element e){
	node* new = (node*)malloc(sizeof(node));
	new->val = e;
	new->right = NULL;
	new->left = NULL;
	new->bal = 0;
	return new;
}

int add(BTree* bt, Key k){
//	node* current = bt->root;

//	addNode(bt->root, newNode);
	
	if(bt->root==NULL){
		bt->root = createNode(k);
		return 0;	
	}
	if(k<=bt->root->val){
		if(bt->root->left==NULL){
			bt->root->left = createNode(k);
			return bt->root->bal--;
		}
		else{
			BTree* lt = createTree();
			lt->root = bt->root->left;
			return(bt->root->bal + add(lt, k));
		}
	

	}
	else{
		if(bt->root->right==NULL){
			bt->root->right = createNode(k);
		}
		else{
			BTree* rt = createTree();
			rt->root = bt->root->right;
			add(rt, k);
		}
	
	}

//	printI(bt->root);	

}

void addNode(node* root, node* new){
	
	if(root==NULL){
		root = new;	
		return;
	}
	if(new->val<=root->val){
		if(root->left!=NULL){
			root->left = new;
			return;
		}
		else{addNode(root->left,new);}
	}
	else{
		if(root->right!=NULL){
			root->right = new;
			return;
		}
		else{addNode(root->right,new);}
	}	
}


node find(BTree* bt, Key k);
void delete(BTree* bt, Key k);
node* inOrder(node *nd){
	if(nd!=NULL) nd = nd->right;
	return nd;
}

void printI(node* nd){
	if(nd!=NULL){
		printI(nd->left);
		printf("%d ", nd->val);
		printI(nd->right);
	}	
}



/*
	while(current!=NULL){
		if(k<=current->val){
			if(current->left!=NULL) current = current->left;
			else{
				current->left = newNode;
				current->bal--;
				break;
			}	
		}
		if(k>current->val){
			if(current->right!=NULL) current = current->right;
			else{
				current->right = newnode;
				current->bal++;
				break;
		}
	}
	*/
