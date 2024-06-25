Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

Approach 1
first take a vector and insert preorder into it and then sort such that we get inorder of BST because its sorted by default then traverse preorder and find that element in inorder vector and make a node then go tot left and right recursive.
here we find again and again in inorder via traversing whole array again
Time Complexity goes higher upto N^2


int findPos(vector<int>&inorder,int &val){
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]==val){
            return i;
        }
    }
    return -1;
}
TreeNode *solve(vector<int>&preorder,vector<int>&inorder,int st,int en,int &preidx){
    if(preidx>preorder.size()-1 or st>en){
        return NULL;
    }
    else{
        int position=findPos(inorder,preorder[preidx++]);
        TreeNode *root=new TreeNode(inorder[position]);
        root->left=solve(preorder,inorder,st,position-1,preidx);
        root->right=solve(preorder,inorder,position+1,en,preidx);
        return root;
    }
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        int preidx=0;
        int st=0,en=inorder.size()-1;
        return solve(preorder,inorder,st,en,preidx);
        
    }

To reduce that again and again traversal from inorder we can store index of lement in unordered map so that we can reduce n time into O(1) so overall time complexity reduces

TreeNode *solve(vector<int>&preorder,vector<int>&inorder,int st,int en,int &preidx,unordered_map<int,int>&m){
    if(preidx>preorder.size()-1 or st>en){
        return NULL;
    }
    else{
        int position=m[preorder[preidx++]];
        TreeNode *root=new TreeNode(inorder[position]);
        root->left=solve(preorder,inorder,st,position-1,preidx,m);
        root->right=solve(preorder,inorder,position+1,en,preidx,m);
        return root;
    }
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder=preorder;
        unordered_map<int,int>m;
        sort(inorder.begin(),inorder.end());
        int preidx=0;
        int st=0,en=inorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return solve(preorder,inorder,st,en,preidx,m);
        
    }
