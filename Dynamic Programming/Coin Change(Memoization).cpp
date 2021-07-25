#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
  long long int solution(vector<vector<long long int>>&memo,int s[],int m,int n)
  {
      if(memo[n][m]==-1)
      {
      if(n==0)
      memo[n][m]=1;
      
      else if(m==0)
      memo[n][m]=0;
      
     else if(n<s[m-1])
      {
          memo[n][m]=solution(memo,s,m-1,n);
      }
      
      else{
          memo[n][m]=solution(memo,s,m,n-s[m-1]) + solution(memo,s,m-1,n);
      }
      }
      
      return memo[n][m];
      
  }
    long long int count( int s[], int m, int n )
    {
        vector<vector<long long int>>memo(n+1,vector<long long int>(m+1,-1));
      return solution(memo,s,m,n);
        //code here.
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends
