#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;

int postfixOp(void){
	Stack<int> acc(50);
	char c;
	int x;
	ifstream fileHandle ("in.txt");

	if(fileHandle.is_open()){
		while(fileHandle.get(c) && c != '\n'){
			x = 0;
			while(c == ' '){
				fileHandle.get(c);
			}
			if(c == '+'){
				x = acc.pop() + acc.pop();
			}
			if(c == '*'){
				x = acc.pop() * acc.pop();
			}
			while(isdigit(c) && c >= '0' && c <= '9'){
				x = 10*x + (c -'0');
				fileHandle.get(c);
			}
			acc.push(x);
		}
		fileHandle.close();
		cout << acc.pop() << '\n';
	}
	return 0;
}

int inToPostfix(void){
	Stack<int> save(50);
	char c;
	ifstream fileHandle ("in.txt");

	if(fileHandle.is_open()){
		while(fileHandle.get(c) && c != '\n'){
			if(c == ')'){
				cout.put(save.pop());
			}
			if(c == '+'){
				save.push(c);
			}
			if(c == '*'){
				save.push(c);
			}
			while( c >= '0' && c <= '9'){
				cout.put(c);
				fileHandle.get(c);
			}
			if( c!= '('){
				cout << ' ';
			}
		}
		fileHandle.close();
		cout << '\n';
	}
	return 0;
}

int main(){
	inToPostfix();
	return 0;
}
