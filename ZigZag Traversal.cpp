vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode *>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            vector<int>res;
            for(int i=0;i<n;i++){
                TreeNode *curr=q.front();
                
                q.pop();
                res.push_back(curr->val);

                if(curr->left!=NULL)q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
            }
            if(level%2!=0){
                reverse(res.begin(),res.end());
            }
            ans.push_back(res);
            level++;

        }
        return ans;
    }
