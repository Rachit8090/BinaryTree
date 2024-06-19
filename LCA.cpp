Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Approach 1  (Using Backtracking)
-> as question tells that you have two node and one root node
-> take 2 vectors ans store root to that node path in vectors
->traverse both vector simultaneously and whenever same value exist in both vector return that node.

 bool solve(TreeNode *root,TreeNode *key,vector<int>&ans){
    if(root==NULL){
        return false;
    }
    ans.push_back(root->val);
    if(root->val==key->val){
        return true;
    }
    bool leftPart=solve(root->left,key,ans);
    bool rightPart=solve(root->right,key,ans);
    if(leftPart or rightPart)return true;
    ans.pop_back();
    return false;

}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int>v1,v2;
        solve(root,p,v1);
        solve(root,q,v2);
        int i=0,j=0;
        int n=v1.size(),m=v2.size();
        int ans=0;
        while(i<n and j<m){
            if(v1[i]==v2[j]){
               ans=v1[i];
                
            }
            i++;
            j++;
        }
        TreeNode *node=new TreeNode(ans);
        return node;
    } 




Approach 2 
->using recusrion and inorder traversal

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return root;

        TreeNode* leftpart=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightpart=lowestCommonAncestor(root->right,p,q);

        if(root->val==p->val or root->val==q->val){
            return root;
        }

        if(leftpart==NULL){
            return rightpart;
        }
        else if(rightpart==NULL){
            return leftpart;
        }
        else{
            return root;
        }

    }

Time complexity: O(N) where n is the number of nodes.

Space complexity: O(N), auxiliary space.
  
  
