#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <vector>
typedef unsigned int uint;

struct Node{
	std::string key;
	int value;
	struct Node* next;
};

class LinkedList{
	private:
		struct Node* head;
	public:
		LinkedList();
		~LinkedList();
		int insert(std::string key, int value);
		void print(void);
};

class HashTable{
	private:
		uint table_size = 10;
		std::vector<LinkedList> table;
	public:
		HashTable(uint size = 10);
		~HashTable();
		uint hash(std::string key);
		int insert(std::string key, int value);
};


#endif
