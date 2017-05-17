#include <iostream>

using namespace std;

int mystery(int a, int b)
{
	if (b == 0) return 0;
	if (b % 2 == 0) return mystery(a+a, b/2);
	return mystery(a+a, b/2) + a;
}

int lg( int N){
	int x = 0;
	while( 1<<(x+1) < N){
		x++;
	}
	return x;
}

int main(){
	cout << mystery(3,11) << endl;
	return 0;
}
