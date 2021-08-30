#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    
    int solution(int a[],int n)
    {
        if(n==1)
        return 0;
        
        int res = INT_MAX;
        for(int i=0;i<=n-2;i++)
        {
            if(i+a[i]>=n-1)
            {
                int sub_res = solution(a,i+1);
                if(sub_res!=INT_MAX)
                res = min(res,sub_res+1);
            }
        }
        
        return res;
    }
    //Function to find minimum number of jumps to reach the end of the array.
    int minimumJumps(int a[], int n){
        
        // your code here
        //return solution(a,n);
        
        int dp[n];
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            dp[i]=INT_MAX;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[j]+j>=i)
                {
                    if(dp[j]!=INT_MAX)
                    dp[i] = min(dp[i],dp[j]+1);
                }
            }
        }
        
        if(dp[n-1]==INT_MAX)
        return -1;
        
        return dp[n-1];
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin>>t;
    while(t--)
    {
        
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minimumJumps(arr, n)<<endl;    // Function to calculate minimum number of jumps
    }
    return 0;
}  // } Driver Code Ends
