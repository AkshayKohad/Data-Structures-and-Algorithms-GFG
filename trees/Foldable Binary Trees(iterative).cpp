void rtraverse(Node*root,vector<int>&b)
{
    queue<Node*>q;
    q.push(root);
     while(q.empty()==false)
    {
        Node*curr = q.front();
        q.pop();
        
        if(curr==NULL)
        {
            b.push_back(-1);
            continue;
        }
        
        else{
            b.push_back(curr->data);
            
            if(curr->right!=NULL)
            {
                q.push(curr->right);
                
            }
            
            else{
                q.push(NULL);
            }
            
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            
            else{
                q.push(NULL);
            }
        }
    }
    
}
void ltraverse(Node*root,vector<int>&a)
{
    queue<Node*>q;
    q.push(root);
    
    while(q.empty()==false)
    {
        Node*curr = q.front();
        q.pop();
        
        if(curr==NULL)
        {
            a.push_back(-1);
            continue;
        }
        
        else{
            a.push_back(curr->data);
            
            if(curr->left!=NULL)
            {
                q.push(curr->left);
                
            }
            
            else{
                q.push(NULL);
            }
            
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
            
            else{
                q.push(NULL);
            }
        }
    }
}
//Function to check whether a binary tree is foldable or not.
bool IsFoldable(Node* root)
{
    if(root==NULL)
    return true;
    
    if(root->left==NULL && root->right==NULL)
    return true;
    
    if(root->left==NULL || root->right==NULL)
    return false;
    
    
    // Your code goes here
    vector<int>a;
    vector<int>b;
    
    ltraverse(root->left,a);
    rtraverse(root->right,b);
    
    // for(int i=0;i<a.size();i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    
    // for(int i=0;i<b.size();i++)
    // {
    //     cout<<b[i]<<" ";
    // }
    
    // cout<<endl;
    if(a.size()!=b.size())
    return false;
    
    
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i] && (a[i]==-1 || b[i]==-1))
        return false;
    }
    return true;
    
}
