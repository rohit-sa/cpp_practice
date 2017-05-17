#include <iostream>
#include <fstream>

using namespace std;


template <class itemType> 
class Queue{
private:
	itemType *queue;
	int head, tail,size;
	
public:
	Queue(int max = 10){
		queue = new itemType[max];
		head = 0; tail =0;
		size = max;
	}
	~Queue(){
		delete queue;
	}
	void enqueue(itemType v);
	itemType dequeue(void);
	inline int empty(){
		cout << "empty" <<endl;
		return head == tail;
	}
};	

template <typename itemType> 
void Queue<itemType>::enqueue(itemType v){
	queue[tail++] = v;
	if(tail > size){
		tail = 0;
	}
}

template <typename itemType> 
itemType Queue<itemType>::dequeue(){
	itemType t = queue[head++];
	if(head > size){
		head = 0;
	}
	return t;
}

int main(){
	Queue<int> queue(3);
	queue.enqueue(5);
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	return 0;
}
