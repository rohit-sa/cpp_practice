#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include"percolation.h"

using namespace std;
const int FULL = 1;
const int OPEN = 0;

class Percolation{
	private:
		vector<int> grid;
		UF uf;
		int N;
	public:
		Percolation(int dim);
		~Percolation(){};
		void open (int i, int j);
		bool isOpen(int i, int j);
		bool isFull(int i, int j);
		bool percolates();
		void printGrid();
};
	
Percolation::Percolation(int dim){
	N = dim;
	grid.resize(N*N);
	uf.load(N*N);
	fill(grid.begin(), grid.end(), FULL);
	
}

void Percolation::open(int i, int j){
	grid[N*i + j] = OPEN;
	if(i > 0 && isOpen(i-1,j)){
		uf.join(N*i + j, N*(i-1) + j);
	}
	if(i < N-1 && isOpen(i+1,j)){
		uf.join(N*i + j, N*(i+1) + j);
	}
	if(j > 0 && isOpen(i,j-1)){
		uf.join(N*i + j, N*i + j-1);
	}
	if(j < N-1 && isOpen(i,j+1)){
		uf.join(N*i + j, N*i + j+1);
	}
}

bool Percolation::isOpen(int i, int j){
	return grid[N*i + j] == OPEN;
}

bool Percolation::isFull(int i, int j){
	return grid[N*i + j] == FULL;
}

bool Percolation::percolates(){
	for(int t_row_val = 0; t_row_val < N; t_row_val++){
		for(int b_row_val = N*(N-1); b_row_val < (N*N); b_row_val++){
			if(uf.connected(t_row_val, b_row_val)){
				return 1;
			}
		}
	}
	return 0;
}

void Percolation::printGrid(){
	for(int i =0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(isOpen(i,j)){
				cout << "0";
			}
			else{
				cout << "*";
			}
		}
		cout << endl;
	}
}

int main(){
	clock_t t_start = clock();
	int N = 20, i = 0, j = 0;
	int no_exp = 100;
	float run_avg = 0;
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> distribution(0,N-1);
	for(int exp = 0; exp < no_exp; exp++){
		int count = 0;
		Percolation mat(N);
		while(!mat.percolates()){
			do{
				i = distribution(rng);
				j = distribution(rng);
				if(mat.isFull(i,j)){
					mat.open(i,j);
					count++;
				}
			}while(mat.isFull(i,j));
		}
		run_avg += ((float)count/(float)(N*N));
	}
	cout << run_avg/no_exp << endl;
	double elapsed_time = (double)(clock() - t_start)/CLOCKS_PER_SEC;
	cout << "Execution time : " << elapsed_time << endl;
	return 0;
}
	
