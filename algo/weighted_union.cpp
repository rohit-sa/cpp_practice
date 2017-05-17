#include<iostream>
#include<vector>

using namespace std;

class wUF{
	private:
		vector<int> id;
		vector<int> size;
	public:
		wUF(int N);
		~wUF(){};
		int root(int i);
		void join(int p, int q);
		bool connected(int p, int q);
};

wUF::wUF(int N){
	id.resize(N);
	size.resize(N,1);
	for(int i = 0; i < N; i++){
		id[i] = i;
	}
}

int wUF::root(int i){
	while(i != id[i]){
		id[i] = id[id[i]];
		i = id[i];
	}
	return id[i];
}

bool wUF::connected(int p, int q){
	return root(p) == root(q);
}

void wUF::join(int p, int q){
	int pid = root(p);
	int qid = root(q);
	cout << pid << " " << qid << endl;
	if(pid == qid) return;
	if(size[pid] < size[qid]){
		id[pid] = qid;
		size[qid] += size[pid];
	}
	else{
		id[qid] = pid;
		size[pid] += size[qid];
	}
}

int main(){
	wUF wuf_ds(5);
	wuf_ds.join(0,1);
	wuf_ds.join(1,2);
	wuf_ds.join(3,4);
	wuf_ds.join(0,3);
	cout << wuf_ds.connected(1,4);
	return 0;
}
