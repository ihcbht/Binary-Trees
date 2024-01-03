class Solution
{
    public:
    pair<bool,int> isSumTreeF(Node *root){
        if(root==NULL){
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        if(root->left==NULL && root->right==NULL){
            pair<bool,int>p=make_pair(true,root->data);
            return p;
        }
        pair<bool,int> leftans=isSumTreeF(root->left);
        pair<bool,int> rightans=isSumTreeF(root->right);
        bool left=leftans.first;
        bool right=rightans.first;
        bool condn=root->data == (leftans.second+rightans.second);
        pair<bool,int> ans;
        if(left && right && condn){
            ans.first=true;
            ans.second=2*root->data;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         return isSumTreeF(root).first;
    }
};