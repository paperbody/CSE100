
#include <iostream>
#include <vector>
#include <list>
//#include <string>

using namespace std;


int HashFunction(int key, int size){
    int index = 0;
    index = key % size;
    return index;
}


void Hashinsert(list<int> Hashtable[], int key, int index){
    //<list<int>> head;
//    if (Hashtable.empty()){
        Hashtable[index].push_front(key);
       // cout<<Hashtable[index].size()<<" "<< index;
        //cout<<key;
  //  }
    //else{
       // head = Hashtable[index].begin();
        // Hashtable.insert(head, key);
       // return Hashtable;
        
    //}
}

int HashSearch(list<int> Hashtable[], int key, int index){
    list<int>::iterator it;
    int count = 0;
    for (it = Hashtable[index].begin(); it != Hashtable[index].end();){
        if (*it == key){
            return count;
        }
        count++;
        it++;
    } 
    return -1;
}

void Hashdelete(list<int>Hashtable[], int key, int index, int position){
        list<int>::iterator it1;
        list<int>::iterator it2;
    int count = 0;
    for (it1 = Hashtable[index].begin(); it1 != Hashtable[index].end();it1++){
        it2 = it1;
        if (position == count){
            it1++;
            //cout<<*it2<<endl;
            Hashtable[index].erase(it2);
        }
        count++;
    }
}

void print(list<int> Hashtable[], int size){
	list<int>::iterator it;
            for (int i = 0; i <= size-1; i++){
                 //cout<<Hashtable[i].size()<<endl;
                cout<<i<<" : ";
                if (Hashtable[i].size() > 0){
                    //for(int i = 0; i <= copy[i].size(); i++){   
                    for ( it = Hashtable[i].begin(); it != Hashtable[i].end();){ 
					cout<<*it;
                    it++;
                    if (it != Hashtable[i].end()){
                        cout<<"->";
                    }
                        //cout<< "hi";
                    //    copy[i].pop_front();
                    //Hashtable++;
                    }
                    //if (Hashtable[i].size() > 1){
                        
                    //}
                }
                cout<<endl;
            }
          cout<<"++++++++++++++++++++"<<endl;
}

/*
void Hashprint(list<int> Hashtable, int size){
    
    for (int i = 0; i <= size-1; i++ ){
        cout<<i<<":";
        //while ()
    }
    
}
*/
int main()
{
    int size;
    cin>> size;
    list<int>* Hashtable = new list<int>[size];
    //list<int> a; 
    char command;
    int index;
    int key;
    bool k = true;
    
    //for(int i = 0; i <= size-1; i ++){
       //Hashtable[i].push_back(a);
    //}
    
    while (k == true){
      //while (getline(cin, )) 
       // if (command.length() > 1){
            //oper = command[0];
            //key = (int)command[1];
            //index = HashFunction(key, size);
        //}
        cin>>command;
        
         if (command == 'e'){
            // cout<<"hi"<<endl;
          k = false;
          break;
        }
        else if (command == 'i'){
            cin>>key;
            index = HashFunction(key, size);
            //cout<<"hello"<<endl;
            Hashinsert(Hashtable, key, index);
          
        }
        else if (command == 'o'){
         //Hashprint(Hashtable[], size);
         //list<int>* copy = Hashtable;
		 print(Hashtable, size);
		 /*
           list<int>::iterator it;
            for (int i = 0; i <= size-1; i++){
                 //cout<<Hashtable[i].size()<<endl;
                cout<<i<<" : ";
                if (Hashtable[i].size() > 0){
                    //for(int i = 0; i <= copy[i].size(); i++){   
                    for ( it = Hashtable[i].begin(); it != Hashtable[i].end();){ 
					cout<<*it;
                    it++;
                    if (it != Hashtable[i].end()){
                        cout<<"->";
                    }
                        //cout<< "hi";
                    //    copy[i].pop_front();
                    //Hashtable++;
                    }
                    //if (Hashtable[i].size() > 1){
                        
                    //}
                }
                cout<<endl;
            }
          cout<<"++++++++++++++++++++"<<endl;
         */
        }
        else if (command == 's'){
            cin>>key;
            int position;
            index = HashFunction(key, size);
            position = HashSearch(Hashtable, key, index);
            if(position == -1){
                cout<<key<<" : NOT FOUND"<<endl;
            }
            else {
                cout<< key<<" : FOUND AT "<<index<<","<<position<<endl;  
            }
             cout<<"++++++++++++++++++++"<<endl;
        }
        
        else if (command == 'd'){
            cin>>key;
            int position;
            index = HashFunction(key, size);
            position = HashSearch(Hashtable, key, index);
            if(position == -1){
                cout<<key<<" : DELETE FAILED"<<endl;
            }
            else {
                Hashdelete(Hashtable, key, index, position);
                cout<<key<<" : DELETED" <<endl;  
            }
            cout<<"++++++++++++++++++++"<<endl;
        }
        
        
    }
    
    
    
    //cout<<"Hello World";

    return 0;
}
