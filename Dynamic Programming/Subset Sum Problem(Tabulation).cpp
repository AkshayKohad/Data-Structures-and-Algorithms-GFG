// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template in C++


class Solution
{
    public:
    
    
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    bool findPartition(int a[], int n)
    {
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = sum + a[i];
        }
        // code here
        
       // vector<vector<int>>memo(n+1,vector<int>(sum+1,-1));
       bool dp[n+1][sum+1];
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=true;
        }
        
        for(int i=1;i<=sum;i++)
        {
            dp[0][i]=false;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j-a[i-1]-a[i-1]<0)
                dp[i][j]=false;
                
                else{
                    dp[i][j] = dp[i-1][j-a[i-1]-a[i-1]] || dp[i-1][j];
                }
            }
        }
        // if(solution(a,n,sum,memo))
        // return true;
        
        // return false;
        return dp[n][sum];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking total testcases
    int tc;
    cin >> tc;
    while (tc--) {
        
        //taking size of array
        int n, i;
        cin >> n;
        int a[n];
        
        //inserting elements in the array
        for (i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        //calling findPartition() function and
        //printing "YES", if it returns true
        //else "NO"
        if (ob.findPartition(a, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
  // } Driver Code Ends
