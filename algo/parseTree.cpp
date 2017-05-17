#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;

struct node{
	char info;
	struct node *l, *r;
};

int traverse(struct node *t);

struct node *x, *z;

int main(){
	char c;
	Stack<node*> stack(50);
	z = new node;
	z->l = z; z->r = z;	
	ifstream fileHandle ("in.txt");

	if(fileHandle.is_open()){
		while(fileHandle.get(c) && c != '\n'){
			x = new node;
			while(c == ' '){
				fileHandle.get(c);
			}
			x->info = c;
			x->l = z;
			x->r = z;
			if(c == '+'|| c == '*'){
				x->r = stack.pop();
				x->l = stack.pop();
			}
			stack.push(x);
			//cout << x->info << " ";
		}
		fileHandle.close();
	}
	traverse(x);
	return 0;
}

int traverse(struct node *t){
	Stack<node*> stackT(50);
	stackT.push(t);
	while(!stackT.empty()){
		t = stackT.pop();
		cout << t->info << " ";
		if(t->r != z){
			stackT.push(t->r);
		}
		if(t->l != z){
			stackT.push(t->l);
		}
	}
	return 0;
}
