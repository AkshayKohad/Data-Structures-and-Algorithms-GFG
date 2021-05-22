void printCorner(Node *root)
{
if(root==NULL)
return;
// Your code goes here
deque<Node*>q;
q.push_back(root);
q.push_back(NULL);
cout<<root->data<<" ";
while(q.size()>1)
{
    Node*curr=q.front();
    q.pop_front();
    if(curr==NULL)
    {
        if(q.front()!=q.back())
        {
        cout<<q.front()->data<<" ";
        cout<<q.back()->data<<" ";
        }
        else{
             cout<<q.front()->data<<" ";
        }
        q.push_back(NULL);
        continue;
    }
    
    if(curr->left!=NULL)
    {
        q.push_back(curr->left);
    }
    
    if(curr->right!=NULL)
    {
        q.push_back(curr->right);
    }
}

}
