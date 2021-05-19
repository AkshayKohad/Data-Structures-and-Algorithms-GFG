lass Solution{
  public:
  void solution(Node*root,int k, int &res, int &count)
  {
      if(root==NULL)
      return;
      
      
      solution(root->left,k,res,count);
      count++;
      if(count==k)
      {
          res=root->data;
          return;
      }
      solution(root->right,k,res,count);
  }
    // Return the Kth smallest element in the given BST 
    int KthSmallestElement(Node *root, int k)
    {
        int res=-1;
        int count=0;
        solution(root,k,res,count);
        return res;
        //add code here.
    }
};
