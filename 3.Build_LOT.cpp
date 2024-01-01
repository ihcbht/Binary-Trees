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


void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}


void buildFromLevelOrder1(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }


int main() {

    node* root = NULL;

    buildFromLevelOrder1(root);
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    


    return 0;
}

/*hp@LAPTOP-N3SCUK8V MINGW64 ~/Desktop/CODES/Trees/BinaryTrees1
$ g++ Build_LOT.cpp 

hp@LAPTOP-N3SCUK8V MINGW64 ~/Desktop/CODES/Trees/BinaryTrees1
$ ./a.exe
Enter data for root
1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
Enter left node for: 1
Enter right node for: 1
Enter left node for: 3
Enter right node for: 3
Enter left node for: 5
Enter right node for: 5
Enter left node for: 7
Enter right node for: 7
Enter left node for: 11
Enter right node for: 11
Enter left node for: 17
Enter right node for: 17
1
3 5
7 11 17 */