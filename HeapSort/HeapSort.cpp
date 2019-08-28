#include <iostream>

using namespace std;

void MaxHeapify(int arr[], int i,int size){
    //int* left = new int[size];
    //int* right = new int[size];
    int l = (2*i);
    int r = (2*i+1);
    int largest = 0; 
    int temp=0;
    
    if (l <= size && arr[l] > arr[i]){
        largest = l;
    }
    else {
        largest = i;
    }
    if (r <= size && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != i ){
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        MaxHeapify(arr,largest,size-1);
    }
}

void BuildMaxHeap(int* arr,int size){
    //int heapsize;
    //heapsize = arr.length;
    for (int i = (size/2); i >= 0; i--){
        MaxHeapify(arr, i, size-1);
    }
}
//void 

void HeapSort(int arr[], int size){
	BuildMaxHeap(arr,size);
    int temp=0;
		// 0 is the first element in the array; i-1 is a.heapsize-1
    for (int i = size; i >= 0; i--){
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        MaxHeapify(arr,0,i-1);
    } 
}

int main()
{
    int size;
    cin>>size;

    int* array = new int[size];
    
    for (int i = 0; i <= size-1; i++){
        cin>> array[i];    
    }
    //BuildMaxHeap(array, size-1);
    HeapSort(array, size-1);

    for (int j = 0; j < size; j++){
    cout<<array[j]<<";";
    }

    return 0;
}
