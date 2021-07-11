//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution {
    public:
    int celebrity(vector<vector<int> >& M, int n) {
        // code here 
            // Initialize two pointers  as two corners 
        int a = 0;
        int b = n - 1;
        
        // Keep moving till the two pointers 
        // don't become same. 
        while (a < b) {
            if (M[a][b])
                a++;
            else
                b--;
        }
        
        // Check if a is actually 
        // a celebrity or not 
        for (int i = 0; i < n; i++){
            // If any person doesn't  
            // know 'a' or 'a' doesn't 
            // know any person, return -1 
            if ( (i != a) && (M[a][i] || !M[i][a]) )
                return -1;
        }
        return a;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends
