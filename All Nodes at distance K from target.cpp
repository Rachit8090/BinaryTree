Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node
Approach 

-> Solve this question as making graph where target is taken as SRC 
-> While traverse level order wise store parent of each node
-> Then again traverse level order wise and check node to all node at distance k or not after that the nodes which are at distance k left in queue these nodes are ans;

void makeParent(TreeNode *root,unordered_map<TreeNode*,TreeNode *>&parent){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode *curr=q.front();
        q.pop();
        if(curr->left!=NULL){
            parent[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            parent[curr->right]=curr;
            q.push(curr->right);
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         vector<int>ans;
         if(!root)return ans;
        unordered_map<TreeNode*,TreeNode *>parent;
        makeParent(root,parent);
        queue<TreeNode *>q;
        q.push(target);
        unordered_map<TreeNode*,bool>vis;
        vis[target]=true;
        int distance=0;
        while(!q.empty()){

            int n=q.size();
            if(distance==k)break;
            for(int i=0;i<n;i++){
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left!=NULL and !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right!=NULL and !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parent[curr]!=NULL and !vis[parent[curr]]){
                    q.push(parent[curr]);
                    vis[parent[curr]]=true;
                }
            }
            distance++;
        }
        while(!q.empty()){
            TreeNode *value=q.front();
            q.pop();
            ans.push_back(value->val);
        }
        return ans;
    }
  
