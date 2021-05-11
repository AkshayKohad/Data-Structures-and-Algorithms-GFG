vector<int> inOrder(Node* root)
{
    vector<int>a;
    
    stack<Node*>s;
   
    Node*curr=root;
    while(curr!=NULL || s.empty()==false)
        {
            while(curr!=NULL)
            {
                s.push(curr);
                curr=curr->left;
            }
        
        
        curr=s.top();
        s.pop();
        a.push_back(curr->data);
        
       
        
        
        curr=curr->right;
        
    }
    
    return a;
    //code here
}
