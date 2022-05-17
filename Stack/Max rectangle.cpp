#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
  int LargestAreaInHistogram(vector<int>a)
    {
        int n = a.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i] = a[i];
        }
        
        stack<int>s;
        
        for(int i=0;i<n;i++)
        {
            if(s.empty()==true)
            {
                s.push(i);
                continue;
            }
            
            while(s.empty()==false && a[s.top()]>=a[i])
            {
                s.pop();
            }
            
            if(s.empty()==true)
            {
                ans[i] += a[i]*(i);
            }
            
            else{
                ans[i] += a[i]*(i-s.top()-1);
            }
            
            s.push(i);
        }
        
        stack<int>s1;
        
        for(int i=n-1;i>=0;i--)
        {
            if(s1.empty()==true)
            {
                s1.push(i);
                continue;
            }
            
            
            while(s1.empty()==false && a[s1.top()]>=a[i])
            {
                s1.pop();   
            }
            
            if(s1.empty()==true)
            {
                ans[i] += a[i]*(n-1-i);
            }
            
            else{
                ans[i] += a[i]*(s1.top()-1-i);
            }
            
            s1.push(i);
        }
        
        int res = 0;
        
        for(int i=0;i<n;i++)
        {
            res = max(res,ans[i]);
        }
        
        return res;
    }
    
    
  
  
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
         int res = 0;
        
        vector<int>a(m,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]==0)
                {
                    a[j] = 0;
                }
                
                else{
                    a[j] += 1;
                }
                
                
            }
            res = max(res,LargestAreaInHistogram(a));
        }
        
        return res;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends
