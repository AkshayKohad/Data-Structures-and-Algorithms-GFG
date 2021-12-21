class Solution{
public:

#define MOD 1000000007
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    ll dp[n+1][2];
	    dp[0][1]=dp[0][2] = 0;
	    dp[1][1] = dp[1][0]=1;
	    
	    for(int i=2;i<=n;i++)
	    {
	        dp[i][0] = (dp[i-1][0] + dp[i-1][1])%MOD;
	        
	        dp[i][1] = dp[i-1][0]%MOD;
	    }
	    
	    return (dp[n][0]+dp[n][1])%MOD;
	}
};
