struct Node{
  int key;
  Node*left;
  Node*right;
   Node(int k)
   {
     key=k;
     left=NULL;
     right=NULL;
   }
  
};




// Inorder traversal
// Left Root Right
void InorderTraversal(Node* root)
{
  if(root!=NULL){
    InorderTraversal(root->left);
    cout<<root->key<<" ";
    InorderTraversal(root->right);
  }
  
}

// Preorder Traversal
// Root Left Right
void PreorderTraversal(Node*root)
{
  if(root!=NULL)
  {
  cout<<root->key<<" ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
  }
}

// Postorder Traversal
// Left Right Root

void PostorderTraversal(Node*root){
  if(root!=NULL){
PostorderTraversal(root->left);
  PostorderTraversal(root->right);
  cout<<root->key<<" ";
}
} 


// Level Order Traversal
void LevelOrder(Node*root){
if(root==NULL)
  return;
  
  queue<Node*>q;
  q.push(root);
  
  while(q.empty()==false){
  Node*curr = q.front();
    q.pop();
    cout<<curr->key<<" ";
    
    if(curr->left!=NULL){
    q.push(curr->left);
    }
    
    if(curr->right!=NULL){
    q.push(curr->right);
    }
  }
}
