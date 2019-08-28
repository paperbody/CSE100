#include <iostream>

using namespace std;

int LinearSearch(int arr[],int key,int size){
    
    for (int i = 0;i < size; i++){
		if (arr[i] == key){
			return i;
    }
       }
    return -1; 
}

int main()
{
    int size;
    //int NumKey = 0;
    int key;

    
    cin>> size;
    int* array= new int[size];
	cin>> key;
    for (int i = 0;i <size; i++){
		cin>>array[i];
	}	
    
    
    int i= LinearSearch(array, key, size);
    
    cout<<i<< endl;


    return 0;
}