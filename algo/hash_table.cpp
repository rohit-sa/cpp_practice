#include <iostream>
#include "hash_table.h"

using namespace std;

LinkedList::LinkedList(){
	head = NULL;
}

LinkedList::~LinkedList(){
	delete head;
}

int LinkedList::insert(std::string key, int value){
	struct Node* new_element = new Node;
	struct Node* p = head;
	new_element->key = key;
	new_element->value = value;
	new_element->next = NULL;
	if(p == NULL){
		head = new_element;
		return 0;
	}
	while( p->next != NULL){
		p = p->next;
	}
	p->next = new_element;
	return 0;
} 

void LinkedList::print(){
	struct Node* p = head;
	while( p != NULL){
		cout << p->key <<" " << p->value << endl;
		p = p->next;
	}
}
	

HashTable::HashTable(uint size){
	table_size = size;
	table.reserve(table_size);
}

HashTable::~HashTable(void){
}	
	
uint HashTable::hash(string key){
	uint hash_value = 0;
	int key_len = key.size();
	for(int i = 0; i < key_len; i++){
		hash_value = (hash_value*31 + key[i]) % table_size;
	}
	return hash_value;
}

int HashTable::insert(string key, int value){
	uint index = hash(key);
	
	return 0;
}

int main(){
	HashTable h_table (11);
	LinkedList list;
	list.insert("as",1);
	list.insert("as",1);
	list.print();
	return 0;
}
