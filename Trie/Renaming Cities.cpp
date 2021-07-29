//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node{
    bool isEndOfWord;
    int count1;
    map<char, Node *> mp;
};

Node *newNode(){
    Node *temp = new Node();
    temp->isEndOfWord = false;
    // int count1 = 0;
    return temp;
}


 // } Driver Code Ends
//User function template for C++

// arr : array of strings
// n : count of the number of strings in the array
class Solution
{
    public:
    
    bool search(string &s,Node*root,string key)
    {
        Node*curr = root;
        if(root==NULL)
        return false;
        
        for(int i=0;i<key.length();i++)
        {
            s=s+key[i];
            if(curr->mp.find(key[i])==curr->mp.end())
            return false;
            
            curr = curr->mp[key[i]];
        }
        
        return curr->isEndOfWord;
        
    }
    
    Node *insert(Node*root,string key)
    {
        Node*curr=root;
        for(int i=0;i<key.length();i++)
        {
            if(curr->mp.find(key[i])==curr->mp.end())
            {
             curr->mp[key[i]] = newNode();   
            }
            
            curr = curr->mp[key[i]];
        }
        
        curr->isEndOfWord = true;
        
        return root;
    }
    

    void check(string *arr, int n){
    //code here
    unordered_map<string,int>m;
    Node*root= newNode();
    
    for(int i=0;i<n;i++)
    {
      string s;
     if(search(s,root,*(arr+i))==false)
     {
      cout<<s<<endl;
      m[*(arr+i)]=1;
      root=insert(root,*(arr+i));
     }
      
      else{
          m[*(arr+i)]++;
          int c = m[*(arr+i)];
          cout<<s<<" "<<c<<endl;
      }
      
    }
    
    }

};




// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string arr[n];
        for(int i = 0;i<n;i++){
            string s;
            cin >> s;
            arr[i] = s;
        }
        Solution obj;
        obj.check(arr,n);
    }
    return 0;
}
  // } Driver Code Ends
