#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

void inorder(node *root, int &count) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left, count);
   	
    //leaf node
    if(root->left == NULL && root->right == NULL) {
        count++;
    }
    
    inorder(root->right, count);

}


int noOfLeafNodes(node *root){
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}




int main() {

    node* root = NULL;
    
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    int count=noOfLeafNodes(root);
    cout<<"The number of Leaf Nodes are "<<count<<endl;
    return 0;
}


// hp@LAPTOP-N3SCUK8V MINGW64 ~/Desktop/CODES/Trees/BinaryTrees1
// $ g++ countLeafNode.cpp 

// hp@LAPTOP-N3SCUK8V MINGW64 ~/Desktop/CODES/Trees/BinaryTrees1
// $ ./a.exe 
// Enter the data: 
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// Enter data for inserting in left of 1
// Enter the data: 
// Enter data for inserting in left of 3
// Enter the data: 
// Enter data for inserting in left of 7
// Enter the data: 
// Enter data for inserting in right of 7
// Enter the data: 
// Enter data for inserting in right of 3
// Enter the data: 
// Enter data for inserting in left of 11
// Enter the data: 
// Enter data for inserting in right of 11
// Enter the data: 
// Enter data for inserting in right of 1
// Enter the data: 
// Enter data for inserting in left of 5
// Enter the data: 
// Enter data for inserting in left of 17
// Enter the data: 
// Enter data for inserting in right of 17
// Enter the data: 
// Enter data for inserting in right of 5
// Enter the data: 
// The number of Leaf Nodes are 3