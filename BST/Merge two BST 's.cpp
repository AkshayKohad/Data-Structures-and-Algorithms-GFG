class Solution
{
    public:
    void Inorder(Node*root,vector<int>&v)
    {
        if(root==NULL)
        return;
        
        Inorder(root->left,v);
        v.push_back(root->data);
        Inorder(root->right,v);
    }
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int>a;
       vector<int>b;
       vector<int>c;
       Inorder(root1,a);
       Inorder(root2,b);
       
    //   for(int i=0;i<a.size();i++)
    //   cout<<a[i]<<" ";
    //   cout<<endl;
       
    //   for(int i=0;i<b.size();i++)
    //   cout<<b[i]<<" ";
    //   cout<<endl;
       
       int i=0;
       int j=0;
       
       while(i<a.size() && j<b.size())
       {
           if(a[i]<b[j])
           {
               c.push_back(a[i]);
               i++;
           }
           
           else{
               c.push_back(b[j]);
               j++;
           }
           
       }
       while(i<a.size())
       {
           c.push_back(a[i]);
               i++;
       }
       
       while(j<b.size())
       {
            c.push_back(b[j]);
               j++;
       }
       return c;
    }
};
