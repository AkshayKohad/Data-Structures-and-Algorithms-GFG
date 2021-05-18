bool solution(Node* root,int x,unordered_set<int>&s)
{
    if(root==NULL)
    return false;
    
    if(x<=root->data)
    {
    return solution(root->left,x,s);
    }
    
    
    
    if(s.size()==0)
    {
        s.insert(root->data);
    }
    
   else if(s.size()!=0)
    {
        if(s.find(x-root->data)!=s.end())
        return true;
        
        else
        s.insert(root->data);
    }
    
    return (solution(root->left,x,s) || solution(root->right,x,s));
    
    
    
    
}

//Function to check if any pair exists in BST whose sum is equal to given value.
bool findPair(Node* root, int x) 
{
    // Your code here
    unordered_set<int>s;
    
    return solution(root,x,s);
}

