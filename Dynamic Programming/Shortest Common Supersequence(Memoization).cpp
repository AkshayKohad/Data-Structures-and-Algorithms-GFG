//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
  
  int solution(vector<vector<int>>&memo,string x,string y,int m,int n)
  {
    if(m==0 || n==0)
    {
      memo[m][n]=0;
    }
    
    else{
      if(x[m-1]==y[n-1])
      {
        memo[m][n] = 1 + solution(memo,x,y,m-1,n-1);
      }
      
      else{
        memo[m][n] = max(solution(memo,x,y,m-1,n),solution(memo,x,y,m,n-1));
      }
    }
    
    
    return memo[m][n];
  }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string x, string y, int m, int n)
    {  
        vector<vector<int>>memo(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                memo[i][j]=-1;
            }
        }
        // we got max common subsequence, now for shortest common supersequence we will subtract max with lenght of both strings and will add the resultant with max 
        
     
      
        int max = solution(memo,x,y,m,n);  
        int ans1 = m - max;  
        int ans2 = n - max;
        int res = ans1 + ans2 + max;
        return res;
        //code here
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends
