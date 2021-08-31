class Solution{
    public:
    long long maximumAmount(int a[], int n){
        // Your code here
        int dp[n][n];
        
        for(int i=0;i<n-1;i++)
        {
            dp[i][i+1] = max(a[i],a[i+1]);
        }
        
        for(int gap=3;gap<n;gap=gap+2)
        {
            for(int i=0;i+gap<n;i++)
            {
                int j = i+gap;
                dp[i][j] = max(a[i] + min(dp[i+2][j],dp[i+1][j-1]), a[j] + min(dp[i+1][j-1],dp[i][j-2]));
                
            }
        }
        
        return dp[0][n-1];
    }
};
