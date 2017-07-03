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
		int remove(std::string key);
		int get(std::string key);
		int find(std::string key);
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
		void print();
		int insert(std::string key, int value);
		int remove(std::string key);
		int get(std::string key);
		int find(std::string key);
};


#endif
