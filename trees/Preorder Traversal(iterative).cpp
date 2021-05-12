vector<int> preOrder(Node* root)
{
    //code here
    vector<int>a;
    stack<Node*>s;
    Node*curr=root;
    
    while(curr!=NULL || s.empty()==false)
    {
        while(curr!=NULL)
        {
            a.push_back(curr->data);
            s.push(curr);
            curr=curr->left;
        }
        
        curr=s.top();
        s.pop();
        curr=curr->right;
        
        
    }
    
    return a;
}
