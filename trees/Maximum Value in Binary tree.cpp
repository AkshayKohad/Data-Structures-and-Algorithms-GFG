int MaxValue(Node*root)
{
if(root==NULL){
return INT_MIN;
}

else{
  return max(root->key, max(MaxValue(root->left),MaxValue(root->right)));
 }
}  
