
#include <iostream>
#include <limits>


using namespace std;

int* BottomUpCutRod(int PriceArray[],int size){
   int* revenue = new int[size+1];
   int* cuts = new int[size+1];
   revenue[0] = 0;
   int q = 0;
   //cout<<size<<endl;
   for (int j = 1; j <= size; j++){
        q = numeric_limits<int>::min();
        //cout<<q<<endl;
        for (int i = 1; i <= j; i++){
           // cout<<"he"<<endl;
            if (q < PriceArray[i] + revenue[j-i]){
          //      cout<<"ha"<<endl;
                q = PriceArray[i] + revenue[j-i];
                //cout<<q<<endl;
                cuts[j] = i;
            }
        }
        //cout<<q<<endl;
        revenue[j] = q;
   }
  // cout<<"hi"<<endl;
   return revenue;
}

int* BottomUpCutRod1(int PriceArray[],int size){
   int* revenue = new int[size+1];
   int* cuts = new int[size+1];
   revenue[0] = 0;
   int q = 0;
   //cout<<size<<endl;
   for (int j = 1; j <= size; j++){
        q = numeric_limits<int>::min();
        //cout<<q<<endl;
        for (int i = 1; i <= j; i++){
           // cout<<"he"<<endl;
            if (q < PriceArray[i] + revenue[j-i]){
          //      cout<<"ha"<<endl;
                q = PriceArray[i] + revenue[j-i];
                //cout<<j<<endl;
                cuts[j] = i;
            }
        }
        //cout<<q<<endl;
        revenue[j] = q;
   }
  // cout<<"hi"<<endl;
   return cuts;
}

void PrintCutRodSolution(int PriceArray[],int size){
    int* revenue = new int[size+1];
    int* cuts = new int[size+1];
    int n = size;
    int m = 0;
    revenue = BottomUpCutRod(PriceArray, size);
    cuts = BottomUpCutRod1(PriceArray, size);
    //cout<<endl;
    cout<<revenue[size]<<endl;
    while (n > 0){
        cout<<cuts[n];
        cout<<" ";
       n = n - cuts[n];
    }
    //cout<<endl;
   //for (int i = 0; i <= size -1; i++){
     //   cout<<revenue[i]<<" ";
    //}
    //cout<<endl;
    //for (int i = 0; i <= size; i++){
      // cout<<cuts[i]<<" ";    
    //}
    //cout<<endl;
    
    
    cout<<"-1"<<endl;
}



int main()
{
    int size = 0;
    int Max = 0;
    //int temp = 0;
    cin>>size;
    
    
    //for (int i = 0; i < size -1; i++){
        int* PriceArray = new int[size+1];
    //}
    
   for(int i = 1; i <= size; i++){
       
       cin>>PriceArray[i];
       //cout<<i<<endl;
   }
   
    //Max = BottomUpCutRod(PriceArray,size);
    PrintCutRodSolution(PriceArray,size);
    //cout<<Max;
    return 0;
}
