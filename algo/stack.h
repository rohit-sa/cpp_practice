#ifndef STACK_H
#define STACK_H

template <class itemType> 
class Stack
{
private:
	itemType *stack;
	int ptr;
public:
	Stack(int max=100){
		stack = new itemType[max];
		ptr = 0;
	}
	~Stack(){
		delete stack;
	}
	inline void push(itemType v){
		stack[ptr++] = v;
	}
	inline itemType pop(){
		return stack[--ptr];
	}
	inline int empty(){
		if(ptr == 0){
			return 1;
		}
		else{
			return 0;
		}
	}
};

#endif
