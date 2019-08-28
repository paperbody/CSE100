
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> CountSort(vector<vector<int>>&outVector,vector<vector<int>>&cloneOut,int digit, int size, int postnum){

	int C[postnum];
	for (int i = 0; i < postnum; i++){
		C[i] = 0;
		/*
		    for (int k = 0; k < postnum; k++){
            cout<<C[i]<<";";
        }
	*/
	}
	
    for (int j = 0; j <= outVector.size()-1; j++){
        C[outVector[j][digit]] = C[outVector[j][digit]]+1;
        //cout<<"hello"<<endl;
    }
    for (int i = 1; i < postnum; i++){
         //cout<<"hello"<<endl;
        C[i] = C[i] + C[i-1]; 
       
    }
    for (int j = size-1; j >= 0; j--){
       // cout<<"hello"<<endl;
        cloneOut[C[outVector[j][digit]] - 1] = outVector[j];
        C[outVector[j][digit]] = C[outVector[j][digit]]-1;
    }
    return cloneOut; 
}

vector<vector<int>> RadixSort(vector<vector<int>> outVector,vector<vector<int>> cloneOut,int size,int digit, int postnum) {
	vector<vector<int>> temp = outVector;
	/*
	    for (int k = 0; k <= size-1; k++){
        for(int l = 0; l <= digit-1; l++){
            cout<<temp[k][l]<<";";
        }
        cout<<endl;
    }
	*/
	for (int i = digit-1; i >= 0; i--){
		temp = CountSort(temp,cloneOut, i, size, postnum);
	}
	/*
	    for (int k = 0; k <= size-1; k++){
        for(int l = 0; l <= digit-1; l++){
            //cloneOut[k][l];
            cout<<temp[k][l]<<";";
        }
        cout<<endl;
    }
	*/

	return temp;
	}

int main()
{
    int size = 0;
    int temp = 0;
    int digit = 10;
    int zero = 0;
	int postnum = 10;
    //string dummy = "0";
    cin >>size;
    //cin >>dummy;
    
    //vector<int>* array = new int[size];
    vector<vector<int>> outVector;
    vector<vector<int>> cloneOut;
    
    //cin vector
    for (int i = 0; i <= size-1; i++){
        vector<int> inVector;
        vector<int> CloneIn;
        for (int j = 0; j <= digit-1; j++){
            cin>>temp;
            //cin>>dummy;
            inVector.push_back(temp);
            CloneIn.push_back(zero);
    }
    //array[i]=vector;
    outVector.push_back(inVector);
    cloneOut.push_back(CloneIn);
}
    cloneOut = RadixSort(outVector,cloneOut,size,digit,postnum);
    
    //cout vector 
    
    for (int k = 0; k <= size-1; k++){
        for(int l = 0; l <= digit-1; l++){
            //cloneOut[k][l];
            cout<<cloneOut[k][l]<<";";
        }
        cout<<endl;
    }
    

    return 0;
}
