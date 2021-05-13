//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    Node* solution(int in[], int pre[],int is,int ie,int &preIndex)
    {
      if(is>ie)
      return NULL;
      
      Node*root = new Node(pre[preIndex++]);
      
      int Index;
      
      for(int i=is;i<=ie;i++)
      {
          if(in[i]==root->data)
          {
              Index=i;
              break;
          }
      }
      
      root->left = solution(in,pre,is,Index-1,preIndex);
      root->right = solution(in,pre,Index+1,ie,preIndex);
      
      return root;
      
    }
    
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preIndex=0;
       return solution(in,pre,0,n-1,preIndex);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends
