You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

Code

TreeNode* solve(TreeNode *root,TreeNode *node){
    if(!root)return node;
    if(root->val>node->val){
        root->left=solve(root->left,node);
    }
    else if(root->val<node->val){
        root->right=solve(root->right,node);
    }
    return root;
}
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *node=new TreeNode(val);
        return solve(root,node);
    }
