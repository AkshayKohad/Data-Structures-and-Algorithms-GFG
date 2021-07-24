
 // } Driver Code Ends
class Solution {
  public:
  
  int solution(vector<vector<int>>&memo,string s,string t,int m,int n)
  {
      if(memo[m][n]==-1)
      {
      if(m==0)
      memo[m][n]=n;
      
     else if(n==0)
      memo[m][n]=m;
 else{      
   if(s[m-1]==t[n-1])
   {
       memo[m][n] = solution(memo,s,t,m-1,n-1);
   }
   
   else{
       int ans1 = solution(memo,s,t,m-1,n-1);
       int ans2 = solution(memo,s,t,m-1,n);
       int ans3 = solution(memo,s,t,m,n-1);
       
       int ans4 = min(ans1,ans2);
       int ans = min(ans3,ans4);
       memo[m][n] = 1 + ans;
   }
 }
   
  }  
      return memo[m][n];
  }
  
  
    int editDistance(string s, string t) {
        // Code here
        int m = s.length();
        int n = t.length();
        
        vector<vector<int>>memo(m+1,vector<int>(n+1,-1));
        
        return solution(memo,s,t,m,n);
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
