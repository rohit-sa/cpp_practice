#include "linked_list.h"
using namespace std;

Linked_List::Linked_List(){
	list = NULL;
}

void Linked_List::insert_last(int value){
	struct node *p = list;
	struct node *new_element = new node;
	new_element->key = value;
	new_element->next = NULL;
	if(p == NULL){
		list = new_element;
		return;
	}
	while(p->next != NULL){
		p = p->next;
	}
	p->next = new_element;
}		

void Linked_List::insert_first(int value){
	struct node *new_element = new node;
	struct node *p = list;
	if(p == NULL){
		list = new node;
		list->key = value;
		list->next = NULL;
		return;
	}
	new_element->key = p->key;
	new_element->next = p->next;
	p->key = value;
	p->next = new_element;	
}	

void Linked_List::remove_last(void){
	struct node *p = list;
	if(p == NULL){
		return;
	}
	struct node *q = p->next;
	if(q == NULL){
		delete p;
		list = NULL;
		return;
	}
	while(q->next != NULL){
		p = p->next;
		q = q->next;
	}
	p->next = NULL;
	delete q;
}

void Linked_List::remove_first(void){
	struct node *p = list;
	if(p == NULL){
		return;
	}
	struct node *q = p->next;
	if(q == NULL){
		delete p;
		list = NULL;
		return;
	}
	p->key = q->key;
	p->next = q->next;	
}
		
void Linked_List::remove_after(struct node *p){
	if(p == NULL){
		return;
	}
	struct node *q = p->next;
	if(q == NULL){
		return;
	}
	p->next = q->next;
	delete q;
}
	
void Linked_List::print_list(void){
	struct node *p = list;
	while( p != NULL){
		cout << p->key << " ";
		p = p->next;
	}
	cout << endl;
}
int Linked_List::length(void){
	int len = 0;
	struct node *p = list;
	while(p != NULL){
		p = p->next;
		len++;
	}
	return len;
}
void Linked_List::compress(void){
	struct node *p = list;
	if(p == NULL){ return;}
	if(p->next == NULL){ return;}
	while(p != NULL){
		struct node *q = p->next;
		while( q != NULL && p->key == q->key){
			q = q->next;
		}
		p->next = q;
		p = p->next;
	}
}

