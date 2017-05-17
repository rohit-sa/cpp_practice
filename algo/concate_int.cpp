#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int fast_compare(int a, int b){
	string s_a = to_string(a), s_b = to_string(b);
	return stoi(s_a + s_b) - stoi(s_b + s_a);
}

int compare(int a, int b){
	vector <int> a_array, b_array;
	while(a/10 != 0){
		a_array.push_back(a%10);
		a = a/10;
	}
	a_array.push_back(a);
	while(b/10 != 0){
		b_array.push_back(b%10);
		b = b/10;
	}
	b_array.push_back(b);
	int a_len = a_array.size();
	int b_len = b_array.size();
	int a_i = a_len - 1;
	int b_i = b_len - 1;
	int total_comp = ((a_len > b_len) ? a_len:b_len);
	while(total_comp > 0){
		if(a_array[a_i] > b_array[b_i]){return 1;}
		else if(a_array[a_i] < b_array[b_i]){return -1;}
		else{
			if(a_i - 1 >= 0){ 
				a_i--;
			}
			if(b_i - 1 >= 0){ 
				b_i--;
			}
		}
		total_comp--;
	}
			
	return 0;
}

int main(){
	string input;
	getline(cin,input);
	istringstream s_input(input);
	int n;
	vector<int> in_array;
	while(s_input >> n){
		in_array.push_back(n);
	}
	int len = in_array.size();
	for(int i = 0; i < len-1; i++){
		int min = in_array[i];
		int min_pos = i;
		for(int j = i+1; j < len; j++){
			//~ if(compare(min, in_array[j]) > 0){
			if(fast_compare(min, in_array[j]) > 0){
				min = in_array[j];
				min_pos = j;
			}
		}
		in_array[min_pos] = in_array[i];
		in_array[i] = min;
	}
	ostringstream s_small(""), s_big(""); 
	for(int i = 0; i < len; i++){
		s_big << in_array[len-1-i];
		s_small << in_array[i];
	}
	cout << s_small.str() << endl;
	cout << s_big.str() << endl;
	
	return 0;
}


	
