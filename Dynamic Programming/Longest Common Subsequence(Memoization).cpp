#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int solution(vector<vector<int>>&memo,int x,int y,string s1,string s2)
    {
     if(memo[x][y]!=-1)
     return memo[x][y];
     
     if(x==0 || y==0)
     memo[x][y] = 0;
     
     else{
         if(s1[x-1] == s2[y-1])
         {
             memo[x][y] = 1 + solution(memo,x-1,y-1,s1,s2);
         }
         
         else{
             memo[x][y] = max(solution(memo,x-1,y,s1,s2),solution(memo,x,y-1,s1,s2));
         }
     }
     
     return memo[x][y];
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> memo(x+1,vector<int>(y+1));
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                memo[i][j]=-1;
            }
        }
        
        return solution(memo,x,y,s1,s2);
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends
