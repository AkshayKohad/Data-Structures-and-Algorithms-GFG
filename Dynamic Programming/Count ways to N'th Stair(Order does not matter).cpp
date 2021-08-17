class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int n)
    {
        // your code here
     int dp[n+1];
     dp[1]=1;
     
     for(int i=2;i<=n;i++)
     {
         if(i%2==0)
         {
             dp[i]=dp[i-1]+1;
         }
         
         else{
             dp[i]=dp[i-1];
         }
     }
      return dp[n];
    }
};
