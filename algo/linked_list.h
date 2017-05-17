#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

struct node{
	int key;
	struct node * next;
};

class Linked_List{
		struct node *list;
	public:
		Linked_List();
		void insert_first(int value);
		void insert_last(int value);
		void print_list(void);
		void remove_first(void);
		void remove_last(void);
		void remove_after(struct node *p);
		int length(void);
		void compress(void);
};

#endif
