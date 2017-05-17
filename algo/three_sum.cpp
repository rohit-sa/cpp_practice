#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void bubble_sort(vector<int> *array_list);
int binary_search(vector<int> *array_list, int key);

void bubble_sort(vector<int> *array_list){
	int len = (*array_list).size();
	for(int i = 0; i < len-1; i++){
		for(int j = i+1; j < len; j++){
			if((*array_list)[i] > (*array_list)[j]){
				int temp = (*array_list)[i];
				(*array_list)[i] = (*array_list)[j];
				(*array_list)[j] = temp;
			}
		}
	}
}

int binary_search(vector<int> *array_list, int key){
	int high = (*array_list).size()-1;
	int low = 0;
	while(low < high){
		int mid = low + (high -low)/2;
		if((*array_list)[mid] > key){
			high = mid - 1;
		}
		else if((*array_list)[mid] < key){
			low = mid + 1;
		}
		else{
			return mid;
		}
	}
	return -1;
}

int main(){
	clock_t start_time = clock();
	vector<int> array_list {5, 3, 2, 1, 8, 3, -2, -6, -3};
	int len = array_list.size();
	int pos = 0;
	
	bubble_sort(&array_list);
	for(int i= 0; i < len - 1; i++){
		for(int j = i+1; j < len; j++){
			pos = binary_search(&array_list, -(array_list[i] + array_list[j]));
			if( pos != -1 && array_list[i] < array_list[j] && array_list[j] < array_list[pos]){
				cout << array_list[i] << " " << array_list[j] << " " << array_list[pos] << endl;
			}
		}
	}
	double exec_time = double(clock() - start_time)/CLOCKS_PER_SEC;
	cout << "Exec time: " << exec_time;
	return 0;
}
