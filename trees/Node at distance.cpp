//METHOD 1

void solution(Node*root, int k ,int p, vector<Node*>&s, unordered_set<Node*>&u)
{
    s.push_back(root);
    
    if(root==NULL)
    {
        s.pop_back();
    return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        if(p>=k)
        {
            if(u.find(s[s.size()-k-1]) ==u.end())
            {
              
              
              u.insert(s[s.size()-k-1]);
              
            }
            
           
            
        }
       // return;
        
    }
    
    solution(root->left,k,p+1,s,u);
    solution(root->right,k,p+1,s,u);
    s.pop_back();
    return;
    
}

//Function to return count of nodes at a given distance from leaf nodes.
int printKDistantfromLeaf(Node* root, int k)
{
    if(root==NULL)
    return 0;
    
 vector<Node*>s;
 unordered_set<Node*>u;
 int res=0;
    solution(root,k,0,s,u);
    
    return u.size();
	//Add your code here. 
}




// Method 2

void kDistantFromLeafUtil(Node* node,int &counter,bool visited[],int pathLen,int k)
{
	//base case
	if (node==NULL) return;

	visited[pathLen] = false;
	pathLen++;

	//if it's a leaf node, we increment the count but only if the 
	//same ancestor at distance k is not already counted.
	if (node->left == NULL && node->right == NULL &&
		pathLen-k-1 >= 0 && visited[pathLen-k-1] == false)
	{
		counter++;
		//setting the ancestor as visited so that we won't count it again.
		visited[pathLen-k-1] = true;
		return;
	}

	//if the current node is not a leaf node then we call the function 
	//recursively for left and right subtrees.
	kDistantFromLeafUtil(node->left, counter, visited, pathLen, k);
	kDistantFromLeafUtil(node->right, counter, visited, pathLen, k);
	
}

//Function to return count of nodes at a given distance from leaf nodes.
int printKDistantfromLeaf(Node* node, int k)
{
	int counter = 0;
	bool visited[MAX_HEIGHT] = {false};
	kDistantFromLeafUtil(node, counter, visited, 0, k);
	
	//returning the count.
	return counter;
}
