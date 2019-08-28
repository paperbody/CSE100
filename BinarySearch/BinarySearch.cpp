#include <iostream>

using namespace std;

int BinarySearch(int arr[],int key, int low, int high){
    int mid;
    while(low <= high){
        mid = (low+high)/2;
        if (arr[mid] == key){
            return mid;
        }
        else if (key < arr[mid]){
            high = mid-1;
            BinarySearch(arr, key, low, high);
        }
        else if (key > arr[mid]){
            low = mid+1;
            BinarySearch(arr,key,low,high);
        }
    }
    return -1;

}

int main()
{
    int size = 0;
    //int NumKey = 0;
    int key = 0;

    
    cin>> size;
    int* array= new int[size];
    cin>> key;
    for (int i = 0;i <size; i++){
		cin>>array[i];
	}	
    
    
    int i= BinarySearch(array, key, 0 ,size);
    
    cout<<i;


    return 0;
}
