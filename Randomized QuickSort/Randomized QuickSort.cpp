
#include <iostream>
#include <stdlib.h> // srand  rand
#include <time.h> // Timer Null

using namespace std;

int Partition (int arr[], int p, int size){
    int x = 0;
    int i = 0;
    int temp=0;
    
    x = arr[size];
    i = p - 1;
    for (int j = p; j <= size-1; j++){
        if (arr[j] <= x){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[size];
    arr[size] = temp;
    return i+1;
}

//int Random(int p, int size){
	//int randomNum;
	//srand(time(NULL));
	//randomNum = p + rand() % (size-p);
	//return randomNum;
//}

int RandomPartition(int arr[], int p, int size){
    int randomNum;
    int temp;
    srand(time(NULL));
    //randomNum = Random(p,size); 
	// random a number between p and size 
    randomNum = p + rand() % (size-p);
    temp = arr[randomNum];
    arr[randomNum] = arr[size];
    arr[size] = temp;
    return Partition(arr, p, size);
    
}

void RandomizedQuickSort(int arr[], int p, int size){
    //int temp = 0;
    int q = 0;
    if (p < size){
		//required random partition
        q = RandomPartition(arr, p, size);
        RandomizedQuickSort(arr, p, q-1);
        RandomizedQuickSort(arr, q+1, size);
        
    }
    
}


int main()
{
    //random seed
    //srand(NULL);
	//randomNum = p + rand() % (size-p);
    int size;
    cin>>size;
    
    int* array = new int [size];
    
    for (int i = 0; i <= size-1; i++){
        cin>>array[i];
    }
    RandomizedQuickSort(array, 0, size-1);
    
    for (int j = 0; j < size; j++){
    cout<<array[j]<<";";
    }
    return 0;
}
