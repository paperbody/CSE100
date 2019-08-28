#include <iostream>

using namespace std;


void insertionSort(int array[],int size){
	int i;
	int j;
	int key;
	for (j = 1;j < size; j++){
		key = array[j];
		i = j-1;
		while (i >= 0 && array[i] > key){
				array[i+1] = array[i];
				i = i-1;
			
		}
		array[i+1] = key;
	}
	
}





int main(){
	
int number;
int size;

    cin >> size;
int* array=new int[size];
	
	for (int i = 0;i<size;i++){ 
	cin>>array[i];
	}
//int array[]={5,2,1,7,8};
	insertionSort(array,size);
	
	
	for (int i = size-1;i >= 0;i--){
	cout<<array[i]<<";";
	}
	return 0;
}