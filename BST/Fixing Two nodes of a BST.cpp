class Solution {
public:

void solution(struct Node* root, struct Node* &error1, struct Node* &error2, struct Node* &max)
{
    if(root==NULL)
    return;
    
    solution(root->left,error1,error2,max);
    if(max!=NULL)
    {
    if(max->data>root->data)
    {
        if(error1==NULL)
        {
            error1=max;
            error2=root;
        }
        else if(error1!=NULL)
        {
            
            error2=root;
        }
        
    }
    max=root;
    }
    else
    max=root;
    
     solution(root->right,error1,error2,max);
    
}
    void correctBST( struct Node* root)
    {
        // add code here.
      struct  Node*error1=NULL;
        struct Node*error2=NULL;
        struct Node*max=NULL;
        solution(root,error1,error2,max);
        int temp;
        if(error1!=NULL && error2!=NULL)
        {
        temp=error1->data;
        error1->data=error2->data;
        error2->data=temp;
        }
    }
};
