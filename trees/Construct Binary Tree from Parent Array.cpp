#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector <int> &v)
{
    sort( v.begin() , v.end() );
    for( int i=0 ; i<v.size() ; i++ )
        cout<< v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root)
{
    vector <int> v;
    queue <Node*> q;
    
    q.push(root);
    
    Node* next_row = NULL;
    
    while(!q.empty())
    {
        Node* n = q.front();
        q.pop();
        
        if(n==next_row)
        {
            sort_and_print(v);
            next_row = NULL;
        }
        
        v.push_back(n->data);
        
        if(n->left)
        {
            q.push(n->left);
            if(next_row == NULL) next_row = n->left;
        }
        
        if(n->right)
        {
            q.push(n->right);
            if(next_row == NULL) next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node *createTree(int parent[], int n);

/* Driver program to test above function*/
int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;
        int a[n];
        for( int i=0 ; i<n ; i++ )
            cin>> a[i];
        
        struct Node *res = createTree(a,n);
        
        printLevelOrder(res);
        cout<<endl;
    }

    return 0;
}

// } Driver Code Ends


/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to construct binary tree from parent array.
Node *createTree(int parent[], int N)
{
    // Your code here
   // vector<Node*>a;
   vector<Node*>a;
   Node*head;
  // Node*q = new Node;
   Node*p= new Node(1);
     for(int i=0;i<N;i++)
     {
         Node*p= new Node(i);
         a.push_back(p);
     }
     int index;
     for(int i=0;i<N;i++)
     {
       if(parent[i]==-1)
       {
           index=i;
           head=a[i];
       }
       
       else{
           if(a[parent[i]]->left==NULL)
           {
               a[parent[i]]->left=a[i];
           }
           
           else{
               a[parent[i]]->right=a[i];
           }
       }
     }
     
     
     
    //  for(int i=0;i<a.size();i++)
    //  {
    //      cout<<a[i]->data<<" ";
    //  }
    //  cout<<endl;
    //  cout<<a.size()<<endl;
    return a[index];
}
