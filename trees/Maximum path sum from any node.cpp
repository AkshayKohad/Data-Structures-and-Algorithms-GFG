class Solution {
  public:
  int solution(Node*root, int &maxi)
  {
      if(root==NULL)
      return 0;
      
      int lh = solution(root->left,maxi);
      int rh = solution(root->right,maxi);
      
      int sum = root->data + lh + rh;
      int sum1 = max(root->data+lh , root->data+rh);
      int sum2 = max(sum,sum1);
      int sum3 = max(root->data,sum2);
       maxi = max(maxi,sum3);
      
      return max(sum1,root->data);
  }
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        if(root==NULL)
        return -2147483648;
        
        if(root->left==NULL && root->right==NULL)
        return root->data;
        
        int maxi=-INT_MIN;
       // cout<<max<<endl;
     solution(root,maxi); 
     // Your code goes here
     return maxi;
    // return 0;
    }
};
