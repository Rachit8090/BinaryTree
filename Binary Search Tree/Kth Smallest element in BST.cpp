Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree

Approach 1 ->using Inorder Traversal
Take inorder Traversal which is sorted by default and return k-1 element from that array

void inorder(TreeNode *root,vector<int>&ans){
    if(!root)return;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root,ans);
        return ans[k-1];
    }

Time Complexity T(N) -> O(N);
Space Complexity -> S(N) -> O(N) + O(N)(Auxillary)

Try to reduce this O(N) taken by vector to store inorder.

void inorder(TreeNode *root,int &k,int &ans){
    if(!root)return ;
    inorder(root->left,k,ans);
    k--;
    if(k==0){
     ans=root->val;
   }
    inorder(root->right,k,ans);
}
    int kthSmallest(TreeNode* root, int k) {
        int ans;
         inorder(root,k,ans);
         return ans;
    }

For further reduce Auxillary space and reduce space upto O(1) use Morris Inorder Traversal
