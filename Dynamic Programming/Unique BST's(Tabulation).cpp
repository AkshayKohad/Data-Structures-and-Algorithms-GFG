class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int n) 
    {
        if(n==0 || n==1)
        return 1;
        
        if(n==2)
        return 2;
        int p = 1000000007;
        // Your code here
        long long dp[n+1];
        fill_n(dp, n + 1, 0);
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            
            for(int j=1;j<=i;j++)
            {
                long long sum = (dp[j-1]*dp[i-j])%p;
                dp[i] = (dp[i] + sum)%p; 
            }
            
            
        }
        
        return dp[n];
    }
};
