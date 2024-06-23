vector <int> bottomView(Node *root) {
        vector<int>ans;
        if(!root){
            return ans;
        }
        map<int,int>m;
        queue<pair<Node *,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
            Node *node=q.front().first;
            int hd=q.front().second;
            q.pop();
            m[hd]=node->data;
            
            if(node->left!=NULL){
                q.push({node->left,hd-1});
            }
            if(node->right!=NULL){
                q.push({node->right,hd+1});
            }
            }
        }
        for(auto x:m){
            ans.push_back(x.second);
        }
        return ans;
    }
