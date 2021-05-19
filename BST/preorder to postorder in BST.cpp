Node* constructTree(int pre[], int n)
{
    stack<Node*>s;
    //code here
    Node*root= newNode(pre[0]);
    Node*p=root;
    int max=root->data;
    s.push(root);
    for(int i=1;i<n;i++)
    {
        if(s.top()->data>pre[i])
        {
            Node*q=newNode(pre[i]);
            s.top()->left=q;
            s.push(q);
            
        }
        
        else{
            Node*curr;
            while(s.empty()==false && s.top()->data<pre[i])
            {
                curr=s.top();
                s.pop();
                
            }
            Node*q=newNode(pre[i]);
            
            curr->right=q;
            s.push(q);
        }
    }
    return root;
}
