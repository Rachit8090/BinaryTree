Given a BST, and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST

Approach 1
Store Inorder in vector and then traverse whole array then find x value and return index +1 elment
 void inorder(Node *root,vector<int>&ans){
      if(!root)return;
      inorder(root->left,ans);
      ans.push_back(root->data);
      inorder(root->right,ans);
  }
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        vector<int>ans;
        Node *res;
        inorder(root,ans);
        if(ans[ans.size()-1]==x->data){
            res=new Node(-1);
        }
        else{
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]==x->data){
                res=new Node(ans[i+1]);
            }
        }
        }
        return res;
        
        //Your code here
    }

Time T(N) -> O(N) + O(N)
  S(N) -> O(N) + O(N)


Approach 2
use 1 pointer curr and traverse whole tree with some condituon and update the curr

Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node *curr=nullptr;
        while(root!=nullptr){
            if(root->data<=x->data){
                curr=root;
                root=root->right;
            }
            else{
                curr=root;
                root=root->left;
            }
        }
        return curr;
        
        //Your code here
    }

T(N) -> O(N)
S(N) -> O(1)
