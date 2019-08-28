
#include <iostream>
#include<limits>
#include<vector>
using namespace std;

void PrintOptimalParents(vector<vector<int>> s,int i,int j){
    if(i == j){
            cout<<"A"<<i-1;
    }
    else{
            cout<<"(";
            PrintOptimalParents(s,i,s[i][j]);
             cout<<".";
            PrintOptimalParents(s,s[i][j]+1,j);
            cout<<")";
    }
       
   }


void MatrixChain (int array[], int size){
    int matrix [size+1][size+1];
    //int matrix2 [size+1][size+1];
    
       vector<vector<int>> matrix2;
    
    for (int z = 0; z < size; z++){
        vector<int> hi;
            for (int x = 0; x < size; x++){
                hi.push_back(0);   
            }
            matrix2.push_back(hi);
    }
    
    int j = 0;
    int temp = 0;
    
    for(int i = 1; i < size; i++){
        matrix[i][i] = 0;
    }
    for (int l = 2; l < size; l++){
        
        for (int i = 1; i < size - l + 1; i++){
            
            j = i + l - 1;
            matrix[i][j] = numeric_limits<int>::max();
           // cout<<matrix[i][j]<<endl;
            for(int k = i; k <= j - 1; k++){
                temp = matrix[i][k] + matrix[k+1][j] + array[i-1]*array[k]*array[j];
                if(temp < matrix[i][j]){
                    matrix[i][j] = temp;
                     //cout<<k;
                    matrix2[i][j] = k;
                   //matrix2.push_back(k);
                }
            }
        }
        
    }
    //for (int x = 0; x < size; x++){
      //  for (int z = 0; z < size; z++){
        //    cout<<matrix2[x][z]<<" ";
        //}
        //cout<<endl;
    //}
    
    //cout<<matrix[1][size-1]<<endl;
    cout<<matrix[1][size-1]<<endl;
    PrintOptimalParents(matrix2,1,size-1);
}
/*
int MatrixChain (int array[], int size){
    //int matrix [size][size];
    int matrix2 [size][size];
    int j = 0;
    int temp = 0;
    for(int i = 1; i < size; i++){
        matrix[i][i] = 0;
    }
    for (int l = 2; l < size; l++){
        for (int i = 1; i < size - l + 1; l++){
            j = i + l - 1;
            matrix[i][j] = numeric_limits<int>::max();
           // cout<<matrix[i][j]<<endl;
            for(int k = i; k <= j-1; k++){
                temp = matrix[i][k] + matrix[k+1][j] + array[i-1]*array[k]*array[j];
                if(temp < matrix[i][j]){
                   // matrix[i][j] = temp;
                   matrix2[i][j] = k;
                }
            }
        }
        
    }
    //cout<<matrix[1][size-1]<<endl;
    return matrix2[1][size-1];
}

    void PrintOptimalParents(s,i,j){
        if(i == j){
            cout<<"A"<<i;
        }
        else{
            cout<<"("
            PrintOptimalParents(s,i,s[i][j]);
            PrintOptimalParents(s,s[i][j]+1,j);
            cout<<")";
        }
        
    }

*/
int main()
{
    int size = 0;
    int num = 0;
    int sum = 0;
    cin>>size;
    
    int* array = new int [size+1];
    
    
    for (int i = 0; i < size+1; i++){
        cin>>array[i]; 
    }
    
    //sum = 
    MatrixChain(array, size+1);
    cout<<endl;
   // cout<<sum<<endl;
    
    //PrintOptimalParents(s,i,j)

    return 0;
}

