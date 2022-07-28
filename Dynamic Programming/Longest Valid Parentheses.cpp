  int maxLength(string s){
        // code here
        
        int n = s.length();
        
        vector<int>dp(n,0);
        
        for(int i=1;i<n;i++)
        {
            if(s[i]=='(')
            {
                dp[i] = 0;
            }
            
            else{
                if(s[i-1]=='(')
                dp[i] = dp[i-2] + 2;
                
                if(s[i-dp[i-1]-1]=='(')
                dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];
            }
        }
        
        int res = 0;
        
        for(int i=0;i<n;i++)
        {
            res = max(res,dp[i]);
        }
        
        return res;
    }
