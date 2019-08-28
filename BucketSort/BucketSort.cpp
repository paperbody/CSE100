#include <iostream> 
#include <vector> 
using namespace std; 
  
void insertionSort(vector<float> &temp, int size){
	int i;
	int j;
	float key;
	for (j = 1; j <= size-1; j++){
		key = temp[j];
		i = j-1;
		    while (i >= 0 && temp[i] > key){
				temp[i+1] = temp[i];
				i = i-1;
		}
		temp[i+1] = key;
	}
}
  

void bucketSort(float array[], int size){ 
//cout<<"hi"<<endl;
    //int* temp = new int [size];
		//vector<float> temp;
    vector<float> temp[size];
    //temp.resize(size);
    
    int index = 0; 
    //for (int i = 0; i <= size-1; i++){
       // temp[i] = 0;
   // }
    
    for (int i = 0; i <= size-1; i++) { 
       //cout<<"hi"<<endl;
	   //creating index to push
	   //temp[size*array[i]].push_back(array[i]);
       index = size*array[i];  
       temp[index].push_back(array[i]); 
    } 
    
    
    for (int i = 0; i <= size-1; i++){ 
        //cout<<"hi"<<endl;
       insertionSort(temp[i], temp[i].size()); 
    }
	//clear index for concatenate
	index = 0;
    for (int i = 0; i <= size-1; i++){
        for (int j = 0; j < temp[i].size(); j++){
				//cout<<"hi"<<endl;
				//index = index + 1;
				swap(array[index], temp[i][j]);
          //array[index] = temp[i][j];
		  	index = index + 1;
        }
    }    
} 
  
int main() {

int size;
cin>>size;

float* array = new float [size];
//vector<float> B;

	for (int i = 0; i <= size-1; i++ ){
	    //cout<<"hi"<<endl;
        cin>>array[i];
        //B[i] = 0;
	}

    bucketSort(array, size); 

    for (int i = 0; i <= size-1; i++) {
       cout << array[i]<<endl; 
	}
    return 0; 
} 