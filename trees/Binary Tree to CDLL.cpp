 Node *bTreeToCList(Node *root)
    {
    //add code here.
    Node*r=root;
        Node*head= newNode(root->data);
        int count=0;
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
        
        if(count==0)
        {
            head->data=curr->data;
            r=head;
            count++;
        }
        else{
            Node*p= newNode(curr->data);
            r->right=p;
            p->left=r;
            r=p;
            count++;
        }
        
        
        curr=curr->right;
        
    }
    
    Node*q=head;
    Node*tail=head;
    
    while(q->right!=NULL)
    {
        q=q->right;
    }
    tail=q;
    tail->right=head;
    head->left=tail;
    
    
    return head;
    }
