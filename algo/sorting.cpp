#include <iostream>
#include <cstdlib>
#include "linked_list.h"

using namespace std;

void selection_sort(int *array, int n){
	for(int i = 0; i < n-1; i++){
		int min = i;
		for(int j = i+1; j < n; j++){
			if(array[j] < array[min]){
				min = j;
			}
		}
		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

void insertion_sort(int *array, int n){
	int j = 0;
	for(int i = 1; i < n; i++){
		j = i;
		while( j > 0 && array[j-1] > array[j]){
			int temp = array[j];
			array[j] = array[j-1];
			array[j-1] = temp;
			j--;
		}
	}
}
		
//~ void shellsort(int *array, int n){
	//~ for(int h = 1; h < n/9; h = 3*h + 1);
	//~ for(; h > 0; h /= 3){
		//~ for(i = h+1; i <= N; i++){
			//~ 
	//~ 
//~ }

void print_array(int *array, int n){
	for(int i=0; i < n; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

int main(){
	int array[10];
	for(int i = 0; i < 10; i++){
		array[i] = rand()%100;
	}
	//~ print_array(array,10);
	//~ selection_sort(array,10);
	insertion_sort(array,10);
	
	//~ print_array(array,10);
	
	Linked_List list;
	list.insert_last(2);
	list.insert_last(2);
	list.insert_last(3);
	list.insert_last(3);
	list.insert_last(3);
	list.insert_last(3);
	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(2);
	//~ list.remove_last();
	//~ list.remove_first();
	list.print_list();
	list.compress();
	list.print_list();
	return 0;
}
