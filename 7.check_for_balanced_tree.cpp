class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<bool,int> isbalancedF(Node *root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        pair<int,int> left=isbalancedF(root->left);
        pair<int,int> right=isbalancedF(root->right);
        
        bool leftans=left.first;
        bool rightans=right.first;
        bool diff=abs(left.second-right.second)<=1;
        
        pair<bool,int> ans;
        ans.second=max(left.second,right.second)+1;
        
        if(leftans && rightans && diff){
            ans.first=true;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return isbalancedF(root).first;
    }
};