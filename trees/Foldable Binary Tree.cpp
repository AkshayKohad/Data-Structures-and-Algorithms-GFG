bool IsFoldableUtil(Node *n1, Node *n2) 
{
    //if both left and right subtrees are NULL then we return true.
    if (n1 == NULL && n2 == NULL) 
    {
        return true;
    }

    //if one of the trees is NULL and other is not then we return false.
    if (n1 == NULL || n2 == NULL) {
        return false;
    }

    //else we check recursively if left and right subtrees are 
    //mirrors of their counterparts.
    return IsFoldableUtil(n1->left,n2->right)&&IsFoldableUtil(n1->right,n2->left);
}

//Function to check whether a binary tree is foldable or not.
bool IsFoldable(Node *root) 
{
    if (root == NULL) 
    {
        return true;
    }
    return IsFoldableUtil(root->left, root->right);
}
