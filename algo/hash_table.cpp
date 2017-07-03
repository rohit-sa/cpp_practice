#include <iostream>
#include <unordered_map>
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
	if(p->key == key){
		p->value = value;
		return 0;
	}
	while( p->next != NULL){
		if(p->key == key){
			p->value = value;
			return 0;
		}
		p = p->next;
	}
	p->next = new_element;
	return 0;
} 

int LinkedList::remove(string key){
	struct Node* p = head;
	struct Node* q;
	if(p == NULL){
		return -1;
	}
	else if(p->key == key){
		head = p->next;
		delete p;
		return 0;
	}
	if(p->next != NULL){
		q = p->next;
	}
	while(q != NULL){
		if(q->key == key){
			p->next = q->next;
			delete q;
			return 0;
		}
		q = q->next;
		p = p->next;
	}
	return -1;
}

int LinkedList::find(string key){
	struct Node* p = head;
	while( p!= NULL){
		if( p->key == key){
			return 1;
		}
	}
	return 0;
}

int LinkedList::get(string key){
	struct Node* p = head;
	while(p != NULL){
		if( p->key == key){
			return p->value;
		}
		p = p->next;
	}
	return -1;
}

void LinkedList::print(){
	struct Node* p = head;
	if(p == NULL){
		return;
	}
	while( p != NULL){
		cout << p->key << " -> " << p->value << "\t";
		p = p->next;
	}
	cout << endl;
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

void HashTable::print(){
	for(uint i = 0; i < table_size; i++){
		table[i].print();
	}
}

int HashTable::insert(string key, int value){
	uint index = hash(key);
	return table[index].insert(key, value);;
}

int HashTable::remove(string key){
	uint index = hash(key);
	return table[index].remove(key);;
}

int HashTable::get(string key){
	uint index = hash(key);
	return table[index].get(key);
}

int HashTable::find(string key){
	uint index = hash(key);
	return table[index].find(key);
}

int main(){
	unordered_map< string, int> h_table;
	return 0;
}
