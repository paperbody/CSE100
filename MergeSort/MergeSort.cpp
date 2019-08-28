
#include <iostream>

using namespace std;



void Merge(int arr[],int low,int mid,int high){
    /*
    int Num1 = mid - low;
    int Num2 = high - mid;
	
    
    int* temparr1 = new int[Num1];
   
    
    for(int i = 0; i < Num1; i++){
        temparr1[i] = arr[low+i];
    }
    for(int j = 0; j < Num2;j++){
        temparr2[j] = arr[mid+1+j];
    }
	*/
	 int* temparr = new int [high-low+1];
	
	int i = low;
	int j = mid+1;
	int k = 0; 
	
    while (i <= mid && j <= high){
        if (arr[i] < arr[j]){
            temparr[k] = arr[i];
            i++;
			k++;
        }
        else {
            temparr[k] = arr[j];
			j++;
			k++;
        }
        //k++;
    }
    
    while(i <= mid){
        temparr[k] = arr[i];
        i++;
        k++;
    }
    
    while (j <= high){
        temparr[k] = arr[j];
        j++;
        k++;
    }
	for (int i =low; i<= high; i++){
		arr[i] = temparr[i-low];
	}
    
}

void MergeSort(int arr[],int low,int high){
    
    int mid;
	
	if(low < high){
     mid = (high+low)/2;
    MergeSort(arr,low,mid);
    
    MergeSort(arr, mid+1, high);
    
    Merge(arr,low,mid,high);
    }

}

int main()
{
    int size = 0;
    //int NumKey = 0;
    int key = 0;

    
    cin>> size;
    int* array= new int[size];
    //cin>> key;
    
    for (int i = 0;i <size; i++){
		cin>>array[i];
	}	
    
    
    MergeSort(array,0 ,size-1);
    
    for (int i = 0;i < size;i++){
    cout<<array[i]<<";";
}

    return 0;
}
