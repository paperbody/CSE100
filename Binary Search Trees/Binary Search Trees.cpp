
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

    struct TreeNode{
        struct TreeNode* parent;
        struct TreeNode* left =NULL;
        struct TreeNode* right = NULL;
        int value = 0;
    };
    
    /*
    TreeNode* TreeInsert(TreeNode* Tree, TreeNode*newNode){
        TreeNode* y = NULL;
        TreeNode* x = Tree;
        //cout<<"hiu"<<endl;
        while (x != NULL){
            cout<<"hiu"<<endl;
            y = x;
            if (newNode->value < x->value){
                cout<<"ma"<<endl;
                x = x->left;
            }
            else{
                 cout<<"ka"<<endl;
                x = x->right;
            } 
        }
        newNode->parent = y;
        if (y == NULL){
             cout<<"hu"<<endl;
            Tree = newNode;
        }
        else if(newNode->value < y->value){
             cout<<"he"<<endl;
            y->left = newNode;
        }
        else {
             cout<<"ha"<<endl;
            y->right = newNode;
        }
    }
    */
	//delete just the root
	TreeNode* rootdelete(TreeNode* Tree){
		if (Tree->left != NULL && Tree->right == NULL){
			return Tree->left;
		}
		else if(Tree->left == NULL && Tree->right != NULL){
			return Tree->right;
		}
	}
	
	
    //From CSE 30
    TreeNode* TreeInsert(TreeNode* Tree, int value) {
	if (Tree == NULL) {
		Tree = new TreeNode();
		Tree->value = value;
		Tree->left = NULL; Tree->right = NULL;
	}
	else {
		if (value < Tree->value) {
			//cout<<Tree->left->value<<endl;
			Tree->left = TreeInsert(Tree->left, value);
		}
		else {
			//cout<<Tree->right->value<<endl
			Tree->right = TreeInsert(Tree->right, value);
		}
	}return Tree;
}


bool search(TreeNode* Tree, int value) {
	if (Tree == NULL) {
		return false;
	}
	else {
		if (Tree->value == value) {
			return true;
		}
		else if (value < Tree->value) {
			//cout<<"hu"<<endl;
			return search(Tree->left, value);
		}
		else {
			//cout<<"hi"<<endl;
			return search(Tree->right, value);
		}
	}
}

//recycle from cse30
void TreeDelete(TreeNode* root, int value) {
	TreeNode* temp = root;
	TreeNode* parent = temp;
	bool left = true;
	while (temp->value != value) {
		parent = temp;
		if (value < temp->value) {
			temp = temp->left; 
			left = true;
		}
		else if (value > temp->value) {
			temp = temp->right; 
			left = false;
		}
	}
	/*
	if(temp->value == value){
		parent == temp;
		if (temp->left != NULL && temp->right == NULL){
			temp = temp->left;
			delete parent;
		}
		else if(temp->left == NULL && temp->right != NULL){
			temp = temp->right;
			delete parent;
		}
	}
	
	*/
	
	if (temp->left == NULL && temp->right == NULL) {
	    // First Case
		if (left == true) {
			parent->left = NULL;
		}
		else {
			parent->right = NULL;
		}
		delete temp;
	}
	//second case
	else if (temp->left != NULL && temp->right == NULL) {
		// Left child only
		TreeNode* leftTree = temp->left;
		//if ()
		//cout<<"hi"<<endl;

		if (left == true) {
			//cout<<"i"<<endl;
			parent->left = leftTree;
		}
		else {
			//cout<<"hi"<<endl;
			parent->right = leftTree;
		}
		delete temp;
	}
	// Thrid case
	else if (temp->left == NULL && temp->right != NULL ) {
		TreeNode* rightTree = temp->right;
		if (left == true) { 
			parent->left = rightTree; 
		}
		else {
			parent->right = rightTree;
		}
		delete temp;
	}
	//Fourth case
	else {
		TreeNode* successor = temp->right;
		while (successor->left != NULL) {
			successor = successor->left;
		}
		int tempVal = successor->value;
		TreeDelete(root, successor->value);
		temp->value = tempVal;
	}
}
     void InorderTreeWalk(TreeNode* Tree){
        //TreeNode x = Tree->value; 
        //cout<<"hi"<<endl;
        if (Tree != NULL){
            
            InorderTreeWalk(Tree->left);
            cout<<Tree->value<<endl;
            InorderTreeWalk(Tree->right);
        }
    }
    
    void preorderTreeWalk(TreeNode* Tree){
        //TreeNode x = Tree->value; 
        //cout<<"hi"<<endl;
        if (Tree != NULL){
            cout<<Tree->value<<endl;    
            preorderTreeWalk(Tree->left);
            preorderTreeWalk(Tree->right);
        }
    }
    
    void postorderTreeWalk(TreeNode* Tree){
        //TreeNode x = Tree->value; 
        //cout<<"hi"<<endl;
        if (Tree != NULL){
            postorderTreeWalk(Tree->left);
			 postorderTreeWalk(Tree->right);
             cout<<Tree->value<<endl;
        }
    }
    


int main()
{
    bool end = false;
    string input;
    int CNum = 0;
    TreeNode* Tree = NULL;
    int key = 0;
    string pre = "pre";
    string post = "post";
    string in = "in";
    bool find = false;
    
    //TreeNode;
    
    while (end == false){
        getline(cin, input);
        //cout<<in<<endl;
        if((input.compare(in)) == 0){
            //cout<<"hi"<<endl;
            InorderTreeWalk(Tree);
            cout<<"++++++++++++++++++++"<<endl;
        }
        
        else if ((input.compare(pre)) == 0){
            preorderTreeWalk(Tree);
            cout<<"++++++++++++++++++++"<<endl;
        }
        
        else if ((input.compare(post)) == 0){
            postorderTreeWalk(Tree);
            cout<<"++++++++++++++++++++"<<endl;
        }
        
        else if(input[0] == 'i'){
            //key = input[1];
            input.erase(input.begin());
            stringstream convert(input);
            convert >> CNum;
            //TreeNode* newNode = new TreeNode();
            //newNode->value = CNum;
            //CNum = CNum-1;
            //input.resize(input.size()-1);
            //cout<<CNum<<endl;
            //Tree = TreeInsert(Tree, newNode);
            Tree = TreeInsert(Tree, CNum);
        }
        else if(input[0] == 'd'){
            input.erase(input.begin());
            stringstream convert(input);
            convert >> CNum;
            //TreeDelete(Tree,CNum);
            
			if (Tree->value == CNum){
				Tree = rootdelete(Tree);
			}
			find = search(Tree, CNum);
            if(find == true){
            TreeDelete(Tree,CNum);
            }
        }
        
        else if (input[0] == 'e'){
            end = true;
        }
    }
  

    return 0;
}
