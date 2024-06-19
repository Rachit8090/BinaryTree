Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes)
where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation

Approach 
-> Traverse Level order and each time maximize difference of first and last index element of level +1
  
int widthOfBinaryTree(TreeNode* root) {
    if(!root)return 0;
        //go level wise but take every node index 
        int maxlen=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            int minIdx=q.front().second;
            int frontPart,lastPart;
            for(int i=0;i<n;i++){
                int level=q.front().second-minIdx;
                TreeNode *curr=q.front().first;
                q.pop();
                if(i==0){
                    frontPart=level;
                }
                if(i==n-1){
                    lastPart=level;
                }
                if(curr->left!=NULL){
                    q.push({curr->left,2*level+1});
                }
                if(curr->right!=NULL){
                    q.push({curr->right,2*level+2});
                }
            }
            maxlen=max(maxlen,lastPart-frontPart+1);
        }
        return maxlen;
        
    }
