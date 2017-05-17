#include<iostream>
#include<vector>

using namespace std;

class UF{
	private:
		vector<int> id;
	public:
		UF(int N);
		~UF(){};
		void join(int p, int q);
		bool connected(int p, int q);
};

UF::UF(int N){
	id.resize(N);
	for(int i = 0; i < N; i++){
		id[i] = i;
	}
}

bool UF::connected(int p, int q){
	return id[p] == id[q];
}

void UF::join(int p, int q){
	int pid = id[p];
	int qid = id[q];
	for(int i = 0; i < (int)id.size(); i++){
		if(id[i] == qid){
			id[i] = pid;
		}
	}
}

int main(){
	UF uf_ds(5);
	uf_ds.join(0,1);
	uf_ds.join(2,4);
	uf_ds.join(2,0);
	cout << uf_ds.connected(1,4);
	return 0;
}
