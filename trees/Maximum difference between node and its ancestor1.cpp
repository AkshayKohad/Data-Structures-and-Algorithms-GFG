//METHOD 1


void solution(Node*root,stack<Node*>&s,int &max,int &maxi)
{
    if(root==NULL)
    return;
    
   
        // if(max==MIN_INT)
        // maxi==MIN_INT;
       
       // else
        //{
        if(max!=-2147483648)
        {
        if(maxi<max-root->data)
        {
        maxi = max-root->data;
        }
        }
       //}
       
       
    if(max<root->data)
    {
    max=root->data;
    s.push(root);
    }
    
    solution(root->left,s,max,maxi);
    solution(root->right,s,max,maxi);
    
    if(root==s.top())
    {
    s.pop();
    if(s.empty()==false)
    max=s.top()->data;
    }
    
    return;
    
}
//Function to return the maximum difference between any node and its ancestor.
int maxDiff(Node* root)
{
    if(root==NULL)
    return -2147483648;
    
    if(root->left==NULL && root->right==NULL)
    return -2147483648;
    
    stack<Node*>s;
    int maxi=-2147483648;
    int max=-2147483648;
    //cout<<maxi<<endl;
    solution(root,s,max,maxi);
    return maxi;
    // Your code here 
}




//METHOD 2
//Function to find the maximum difference.
int maxDiffUtil(Node *t,int *res)
{
    //returning Maximum int value if node is null.
    if (t == NULL) 
        return INT_MAX; 
  
    //if there are no child nodes then we just return data at current node.
    if (t->left == NULL && t->right == NULL) 
        return t->data; 
  
    //recursively calling for left and right subtrees and 
    //choosing their minimum.
    int val = min(maxDiffUtil(t->left, res), 
                  maxDiffUtil(t->right, res)); 
  
    //updating res if (node value - min value from subtrees) is bigger than res.
    *res = max(*res, t->data - val); 
  
    //returning minimum value got so far.
    return min(val, t->data);
}

//Function to return the maximum difference between any node and its ancestor.
int maxDiff(Node *root)
{
    int res=INT_MIN;
    maxDiffUtil(root,&res);
    //returning the result.
    return res;
}
