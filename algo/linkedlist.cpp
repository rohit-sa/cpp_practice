#include<iostream>

using namespace std;

struct node{
	int key;
	struct node *next;
};


int initList(void);
int insert(struct node *t, int keyValue);
int printList(void);

struct node *head, *z;

int main(){

	initList();
	insert(head,5);
	printList();
	return 0;
}

int printList(){
	struct node *i;
	i = head;
	while(i->next != i){
		cout << i->key << " "<< i->next<< endl;;
		i = i->next;
	}
	return 0;
}

int initList(){
	head = new node;
	z = new node;
	head->key = 1;
	head->next = z;
	z->next = z;
	return 0;
}

int insert(struct node *t,int keyValue){
	struct node *x;
	x = new node;
	x->key = keyValue;
	x->next = t->next;
	t->next = x;  //unsafe implementation
	return 0;
}
