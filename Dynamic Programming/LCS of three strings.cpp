int solve(string a,string b,string c,int n1,int n2,int n3,vector<vector<vector<int>>>&memo)
{
    if(n1==0 || n2==0 || n3==0)
    return 0;
    
    if(memo[n1][n2][n3]!=-1)
    return memo[n1][n2][n3];
    
    if(a[n1-1]==b[n2-1] && b[n2-1]==c[n3-1])
    {
        return memo[n1][n2][n3] = 1+solve(a,b,c,n1-1,n2-1,n3-1,memo);
    }
    
    else{
        
return  memo[n1][n2][n3] = max  ({solve(a,b,c,n1-1,n2,n3,memo),
    solve(a,b,c,n1,n2-1,n3,memo),
        solve(a,b,c,n1,n2,n3-1,memo),
        solve(a,b,c,n1-1,n2-1,n3,memo),
        solve(a,b,c,n1-1,n2,n3-1,memo),
        solve(a,b,c,n1,n2-1,n3-1,memo)});
    }
    
    return 0;
}

int LCSof3 (string a, string b, string c, int n1, int n2, int n3)
{
    // your code here
    
    
    vector<vector<vector<int>>>memo(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
   return solve(a,b,c,n1,n2,n3,memo);
}
