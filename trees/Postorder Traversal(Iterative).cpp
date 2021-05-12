vector<int> postOrder(Node* node) {
    // code here
    stack<Node*>s1;
    stack<Node*>s2;
    vector<int>a;
    Node*curr=node;
    while(curr!=NULL || s1.empty()==false || s2.empty()==false)
    {
        while(curr!=NULL)
        {
            s1.push(curr);
            curr=curr->left;
        }
        
        curr=s1.top();
        s1.pop();
        if(curr->right==NULL){
            a.push_back(curr->data);
            while(s1.empty()==false || s2.empty()==false){
                if( s2.empty()==false && s2.top()->right==curr )
                {
                    curr=s2.top();
                    s2.pop();
                    a.push_back(curr->data);
                }
                
              else  if(s1.empty()==false && s1.top()->left==curr && s1.top()->right==NULL )
                {
                    curr=s1.top();
                    s1.pop();
                    a.push_back(curr->data);
                }
                
                else{
                    if(s1.empty()==false ){
                    s2.push(s1.top());
                    curr=s1.top()->right;
                    s1.pop();
                    }
                    break;
                }
            }
        }
        
        else{
            s2.push(curr);
            curr=curr->right;
        }
        
        if(s1.empty()==true && s2.empty()==true)
        break;
    }
    return a;
}
