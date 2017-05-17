#include<iostream>
#include<vector>

using namespace std;

class QU{
	private:
		vector<int> id;
	public:
		QU(int N);
		~QU(){};
		int root(int i);
		void join(int p, int q);
		bool connected(int p, int q);
};

QU::QU(int N){
	id.resize(N);
	for(int i = 0; i < N; i++){
		id[i] = i;
	}
}

int QU::root(int i){
	while(i != id[i]){
		i = id[i];
	}
	return id[i];
}

bool QU::connected(int p, int q){
	return root(p) == root(q);
}

void QU::join(int p, int q){
	int pid = root(p);
	int qid = root(q);
	id[pid] = qid; 
}

int main(){
	QU qu_ds(5);
	qu_ds.join(0,1);
	qu_ds.join(2,4);
	qu_ds.join(2,0);
	cout << qu_ds.connected(1,4);
	return 0;
}
