#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    // int solution(int n,int x,int y,int z)
    // {
    //  if(n<0)
    //     return 0;
        
    //     if(n==0)
    //     return 1;
    // int res1 = solution(n-x,x,y,z);
     
    // int res2 = solution(n-y,x,y,z);
    
    // int res3 = solution(n-z,x,y,z);
    
    
      
    //     int ans1 = max( res1,res2);
    //     int ans = max(ans1,res3);
      
    //     if(ans==0)
    //     return ans;
        
    //     return 1+ ans;   
    // }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        
        
        int dp[n+1];
        dp[0]=1;
        
        for(int i=1;i<=n;i++)
        {
            int res1,res2,res3;
            if(i-x<0)
            res1=0;
            else
            res1 = dp[i-x];
            
            if(i-y<0)
            res2=0;
            
            else
            res2 = dp[i-y];
            
            if(i-z<0)
            res3=0;
            
            else
            res3 = dp[i-z];
            
            int ans1 = max(res1,res2);
            int ans = max(ans1,res3);
            
            if(ans==0)
            dp[i]=ans;
            
            else
            dp[i]=ans+1;
            
        }
        
        if(dp[n]==0)
        return dp[n];
        
        return dp[n]-1;
        
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends
