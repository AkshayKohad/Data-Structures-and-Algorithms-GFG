//Given a binary tree, write a function that returns true if the tree satisfies below property.

//For every node, data value must be equal to sum of data values in left and right children.

bool isCSum(Node*root){
if(root==NULL)
  return true;
if(root->left==NULL && root->right==NULL)
  return true;
  
  int sum=0;
  if(root->left!=NULL)
    sum=sum+root->left->key;
  
  if(root->right!=NULL)
    sum=sum+root->right->key;
  return (root->key==sum && isCSum(root->left) && isCSum(root->right));
}
