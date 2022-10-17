
/*Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/


class NodeValue{
  
  public:
  
    int maxNode,minNode,maxSize;
    
    NodeValue(int maxNode,int minNode,int maxSize)
    {
       this->maxNode = maxNode;
       this->minNode = minNode;
       this->maxSize = maxSize;
    }
    
};


NodeValue *solve(Node*root,int &res)
{
    if(root==NULL)
    {
        return new NodeValue(INT_MIN,INT_MAX,0);
    }
    
    NodeValue*left = solve(root->left,res);
    
    NodeValue*right = solve(root->right,res);
    
    
    if(left->maxNode < root->data && right->minNode > root->data)
    {
        
        int ans = left->maxSize + right->maxSize + 1;
        
        res = max(res,ans);
        
      //  cout<<res<<endl;
        
        int lval = max(root->data,right->maxNode);
        
        int rval = min(root->data,left->minNode);
        
        return new NodeValue(lval,rval,ans);
    }
    
    
    return new NodeValue(INT_MAX,INT_MIN,0);
    
    
    
}


class Solution{
    public:
    
    
    
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	
    	int res = 0;
    	solve(root,res);
    	
    	
    	return res;
    }
};
