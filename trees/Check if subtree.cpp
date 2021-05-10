class Solution
{
  public:
  
  bool identical(Node*T, Node*S)
  {
      if(T==NULL && S==NULL)
      return true;
      
      if(T==NULL || S==NULL)
      return false;
      
      return (T->data==S->data && identical(T->left,S->left) && identical(T->right,S->right));
  }
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
        // Your code here
        if(S==NULL)
        return true;
        
        if(T==NULL)
        return false;
        
        if(identical(T,S))
        return true;
        
        return isSubTree(T->left,S) || isSubTree(T->right,S);
    }
};
