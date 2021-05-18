class Solution
{
    public:
    //Function to find the least absolute difference between any node
    //value of the BST and the given integer.
    int minDiff(Node *root, int k)
    {
        if(!root)
            return INT_MAX;
        
        //if given value is present in BST then least difference would be 0.
        if( root->data == k )
            return 0;
            
        //if data at current node is more than given value, we try to find 
        //the answer by calling function recursively for left subtree.
        if( root->data > k )
            return min( abs(root->data-k) , minDiff(root->left, k) );
        
        //else we call the function recursively for the right subtree.
        return min( abs(root->data-k) , minDiff(root->right, k) );
    }
};
