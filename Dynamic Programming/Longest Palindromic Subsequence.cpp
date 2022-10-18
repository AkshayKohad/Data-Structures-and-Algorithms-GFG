class Solution{
  public:
  
  int solve(string a,string b,int n,int m,vector<vector<int>>&memo)
  {
      if(n==0 || m==0)
      return 0;
      
      
      if(memo[n][m]!=-1)
      return memo[n][m];
      
      if(a[n-1] == b[m-1])
      {
          return memo[n][m] = 1+solve(a,b,n-1,m-1,memo);
      }
      
      else{
          
          return memo[n][m] = max(solve(a,b,n-1,m,memo),solve(a,b,n,m-1,memo));
      }
      
      return 0;
  }
  
    int longestPalinSubseq(string a) {
        //code here
        string b = a;
        
        reverse(b.begin(),b.end());
        
        int n = a.length();
        
        vector<vector<int>>memo(n+1,vector<int>(n+1,-1));
        
       return  solve(a,b,n,n,memo);
    }
};
