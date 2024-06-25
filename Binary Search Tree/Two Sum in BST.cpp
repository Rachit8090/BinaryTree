Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

Approach 


void inorder(TreeNode *root,vector<int>&ans){
    if(!root)return ;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root,ans);
        int i=0,j=ans.size()-1;
        bool res=false;
        while(i<j){
           if(ans[i]+ans[j]==k){
            return true;

           }
           else if(ans[i]+ans[j]>k){
            j--;
           }
           else{
            i++;
           }
    }
    return false;}  
