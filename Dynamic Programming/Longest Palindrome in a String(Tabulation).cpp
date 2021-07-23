#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int m = s.length();
        int dp[m][m];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j]=-1;
            }
        }
        int max=1;
        int index[2];
        index[0]=0;
        int flag=0;
        index[1]=0;
        for(int i=0;i<m;i++)
        {
            dp[i][i]=1;
        }
        
        for(int i=0;i<m-1;i++)
        {
            if(s[i]==s[i+1])
            {
               
                dp[i][i+1]=1;
                dp[i+1][i]=1;
            }
            
            else{
                dp[i][i+1]=0;
                dp[i+1][i]=0;
            }
            
            if(s[i]==s[i+1] && flag==0)
            {
                max=2;
                index[0]=i;
                index[1]=i+1;
                flag=1;
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;i+j<m;j++)
            {
                //int j=i+k;
                if(i+j!=j && j!=j+i+1 && j!=j+i-1)
                {
                    if(s[j]==s[j+i] && dp[j+1][j+i-1]==1)
                    {
                    dp[j][j+i]=1;
                    if(max<(j+i)-j+1)
                    {
                        max=(j+i)-j+1;
                        index[0]=j;
                        index[1]=j+i;
                    }
                    }
                    
                    else{
                        dp[j][j+i]=0;
                    }
                }
            }
        }
        
        
        
        string w;
        for(int i=index[0];i<=index[1];i++)
        w = w + s[i];
        
        return w;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}

  // } Driver Code Ends
