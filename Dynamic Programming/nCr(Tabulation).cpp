// A Dynamic Programming based solution to compute nCr % p 
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



class Solution
{
    public:
    //Function to return nCr mod 10^9+7 for given n and r. 
    int nCrModp(int n, int r) 
    { 
       long long int p = 1000000007;
        if(r>n)
        return 0;
        if(r==n)
        return 1;
      
      // your code here
       int dp[n+1][r+1];
      
      for(int i=0;i<=n;i++)
      {
          dp[i][0]=1;
      }
      
      for(int i=1;i<=r;i++)
      {
          dp[0][i]=-1;
      }
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=r;j++)
          {
              if(i==j)
              dp[i][j]=1;
              
              else if(i>j)
              {
                  dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%p;
                  //dp[i][j] = dp[i][j]% 1000000009;
              }
          }
      }
     
    return dp[n][r];
     
    // return ans;
    } 
};

// { Driver Code Starts.
// Driver program 
int main() 
{ 
  int t, n, r;
  
  //taking count of testcases
  cin >> t;
  
  while(t--){
      
      //taking n and r
      cin >> n >> r;
      Solution ob;
      //calling method nCrModp()
      cout << ob.nCrModp(n, r) << endl;
  }
  
  return 0; 
}
  // } Driver Code Ends
