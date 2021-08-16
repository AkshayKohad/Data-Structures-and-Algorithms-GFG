//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
#define INT_SIZE 32


 // } Driver Code Ends
//User function template for C++

// arr : given array
// n : size of the given array
 struct TrieNode{
   
   int value;
   TrieNode*a[2];
 };


class Solution
{
    public:
    TrieNode*newNode()
    {
        TrieNode*temp = new TrieNode;
        temp->value=0;
        temp->a[0]=NULL;
        temp->a[1]=NULL;
        return temp;
    }
    
    void insert(TrieNode*root,int val)
    {
        TrieNode*temp = root;
        
        for(int i = INT_SIZE-1;i>=0;i--)
        {
            int s = 1 & (val>>i);
            if(temp->a[s]==NULL)
            {
                temp->a[s] = newNode();
            }
            
            temp = temp->a[s];
            
        }
        
        temp->value = val; 
    }
    
    int solution(TrieNode*root,int val)
    {
        TrieNode*temp = root;
        for(int i = INT_SIZE-1;i>=0;i--)
        {
          int s = 1 & (val>>i);
          
          if(temp->a[1-s]!=NULL)
          temp = temp->a[1-s];
          
          else if(temp->a[s]!=NULL)
          temp = temp->a[s];
        }
        
        return val^(temp->value);
    }
    //Function to return maximum XOR value.
    int maxSubarrayXOR(int arr[], int n)
    {
        TrieNode*root = newNode();
        insert(root,0);
        int res = INT_MIN;
        int pre_xor = 0;
        
        for(int i=0;i<n;i++)
        {
            pre_xor = pre_xor^arr[i];
            insert(root,pre_xor);
            
            res = max(res,solution(root,pre_xor));
            
            
        }
        
        return res;
        //code here
    }
};



// { Driver Code Starts.

int main(){
  
  int t;
  cin >> t;
  
  while(t--){
    
    int n;
    cin >> n;
    int arr[n];
    
    for(int i = 0;i<n;i++){
      cin >> arr[i];
    }
    Solution obj;
    cout << obj.maxSubarrayXOR(arr, n) << endl;
    
  }
  
  return 0;
}  // } Driver Code Ends
