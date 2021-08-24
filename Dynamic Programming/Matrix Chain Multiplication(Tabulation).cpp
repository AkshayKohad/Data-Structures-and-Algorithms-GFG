class Solution{
public:
    int matrixMultiplication(int n, int a[])
    {
        // code here
        int dp[n][n];
        for(int i=0;i<n-1;i++)
        dp[i][i+1]=0;
        
        
        for(int gap=2;gap<n;gap++)
        {
            for(int i=0;i+gap<n;i++)
            {
                int j = i+gap;
                dp[i][j] = INT_MAX;
                for(int k=i+1;k<j;k++)
                {
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
