#ifndef PERCOLATION_H
#define PERCOLATION_H

#include <vector>
using namespace std;

class UF{
	private:
		vector<int> id;
		vector<int> size;
	public:
		UF(){};
		void load(int N);
		~UF(){};
		int root(int i);
		void join(int p, int q);
		bool connected(int p, int q);
};

void UF::load(int N){
	id.resize(N);
	size.resize(N,1);
	for(int i = 0; i < N; i++){
		id[i] = i;
	}
}

int UF::root(int i){
	while(i != id[i]){
		id[i] = id[id[i]];
		i = id[i];
	}
	return id[i];
}

bool UF::connected(int p, int q){
	return root(p) == root(q);
}

void UF::join(int p, int q){
	int pid = root(p);
	int qid = root(q);
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
#endif
