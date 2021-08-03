struct TrieNode{
  bool isEnd;
  TrieNode*children[2];
};

TrieNode* newNode()
{
    TrieNode*temp = new TrieNode();
    
    temp->isEnd = false;
    
    temp->children[0] = NULL;
    temp->children[1] = NULL;
    
    return temp;
}

class Solution
{
    public:
    
    void insert(TrieNode*root,int n)
    {
        TrieNode*curr = root;
        for(int i=INT_SIZE-1;i>=0;i--)
        {
            int k = (n>>i)&1;
            
            if(curr->children[k]==NULL)
            curr->children[k] = newNode();
            
            curr=curr->children[k];
        }
        
        curr->isEnd = true;
    }
    
    //Function to return maximum XOR value.
    int maxSubarrayXOR(int arr[], int n)
    {
        int res=INT_MIN;
        TrieNode*root = newNode();
        for(int i=0;i<n;i++)
        {
        insert(root,arr[i]);
        }
        for(int i=0;i<n;i++)
        {
            int count=0;
            TrieNode*head = root;
            
            for(int j=INT_SIZE-1;j>=0;j--)
            {
                int k = (arr[i]>>j)&1;
                
                if(k==1)
                {
                    if(head->children[0]!=NULL)
                    {
                        count = count + pow(2,j);
                        head = head->children[0];
                    }
                    
                    else{
                        head = head->children[1];
                    }
                }
                
                else{
                    if(head->children[1]!=NULL)
                    {
                        count = count + pow(2,j);
                        head = head->children[1];
                    }
                    
                    else{
                        head = head->children[0];
                    }
                }
            }
            
            if(res<count)
            res = count;
        }
        //code here
        return res;
    }
};
