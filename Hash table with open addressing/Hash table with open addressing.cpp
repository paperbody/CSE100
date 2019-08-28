
#include <iostream>
//#include <algorithm>

using namespace std;

int HashFunction1(int key){
    int part1 = 0;
    part1 = (key % 13); 
    return part1;
}

int HashFunction2(int key){
    int part2 = 0;
    part2 = 1+(key % 11);
    return part2;
}

int HashFunction(int key, int i){
    int index = 0;
    int part1 = 0;
    int part2 = 0;
    part1 = HashFunction1(key);
    part2 = HashFunction2(key);
    index = (part1 + (i * part2)) % 13;
    return index;
}
void HashInsert(int array[],int key, int size){
    int i = 0;
    int j = 0;
    //cout<<"hi"<<endl;
    do{
        j = HashFunction(key, i);
        //cout<<key<<": "<<j<<endl;
        if (array[j] == -1){
            array[j] = key;
            break;
        }
        else {
            i = i + 1;
        }
    }while(i != size);
}
int HashSearch(int array[], int key, int size){
    int i = 0;
    int j = 0;
    do{
        j = HashFunction(key, i);
		//cout<<size<<endl;
		//cout<<key<<": " <<array[j]<<endl;
		//cout<<i<<endl;
        if (array[j] == key){
            return j;
        }
        i = i + 1;
    }while(array[j] == -1 || i <= size);
    return -1;
}

void HashDelete(int array[], int key, int size){
    int index = 0;
	//cout<<"index for: "<<key<<endl;
    index = HashSearch(array, key, size);	
    if (index > -1){
        array[index] = -1;
    }
    
}



int main()
{
    int key = 0;
    int* array = new int [13];
    bool end = false;
    bool stage1 = false;
    bool stage2 = false;
    int size = 13;
    int index = 0;
    
    for (int i = 0; i <= size-1; i++){
        array[i] = -1;
    }
    
    while(end == false){
        cin>>key;
        
        if(key >= 0 && stage1 == false && stage2 == false){
            HashInsert(array, key, size);
        }
        
        if (key >= 0 && stage1 == true && stage2 == false){
            index = HashSearch(array, key, size);
			//cout<<key<<": ";
            if (index >= 0){
				cout<<index<<endl;
            }
            else {
                cout<<"NOT_FOUND"<<endl;
            }
        }
        
        if (key >= 0 && stage1 == true && stage2 == true){
            //delete
			//cout<<"hi"<<endl;
            HashDelete(array, key, size);
        }
        else if(key < 0){
             //cout<<key<<endl;
            if (key == -1){
               // cout<<key<<endl;
                for (int i = 0; i <= size-1; i++){
					//cout<<i<<": ";
                    cout<<array[i]<<endl;
                }
                //break;
                stage1 = true;
            }
            else if (key == -2){
                stage2 = true;
            }
			else if(key == -3){            
				for (int i = 0; i <= size-1; i++){
					//cout<<"hello"<<endl;
					if (array[i] == -1){
						cout<<endl;
					}
					else{
						cout<<array[i]<<endl;    
					}  
				}
				end = true;
			}
				
        }
    } 

    return 0;
}
