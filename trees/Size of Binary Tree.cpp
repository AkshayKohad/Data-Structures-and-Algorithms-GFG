int getSize(Node*root){
if(root==NULL)
  return 0;
  
  else
    return 1+ getSize(root->left)+getSize(root->right);
}
