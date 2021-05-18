void solution(Node*root,int x, int &res)
{
if(root==NULL)
return;

if(root->data>x)
solution(root->left,x,res);

else if(root->data<x)
{
    if(res==-1)
    res=root->data;
    
    else{
        if(res<root->data)
        res=root->data;
        
    }
    
    solution(root->right,x,res);
}

else{
    res=x;
    return;
}

}


//Function to return the floor of given number in BST.
int floor(Node* root, int key) 
{ 
	// Your code goes here
	if(root==NULL)
	return -1;
	
	int res=-1;
	
	solution(root,key,res);
	return res;

}
