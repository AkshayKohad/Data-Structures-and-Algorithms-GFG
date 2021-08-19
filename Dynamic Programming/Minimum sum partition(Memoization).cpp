#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

int solution(int a[],int n,int sum,vector<vector<int>>&memo)
{
    if(sum<0)
    return INT_MAX;
    if(memo[n][sum]==-1)
    {
    if(n==0)
    {
    memo[n][sum]=sum;    
    return memo[n][sum];
    }
    memo[n][sum] =  min(min(solution(a,n-1,sum,memo),solution(a,n-1,sum-a[n-1]-a[n-1],memo)),sum);
    }
    return memo[n][sum];
}
  public:
	int minDifference(int a[], int n)  { 
	    // Your code goes here
	    
	   int sum=0;
	   
	    
	    for(int i=0;i<n;i++)
	    {
	        sum = sum + a[i];
	      
	    }
	    
	  
	    
	   // return dp[n][sum];
	   vector<vector<int>>memo(n+1,vector<int>(sum+1,-1));
	   for(int i=0;i<=sum;i++)
	   {
	       memo[0][i] = i;
	   }
	   for(int i=0;i<=n;i++)
	   {
	       memo[i][0] = 0;
	   }
	   return solution(a,n,sum,memo);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
