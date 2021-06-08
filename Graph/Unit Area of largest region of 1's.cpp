#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1}};
    
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&visited, int &count,int m ,int n)
    {
        count++;
        visited[i][j]=1;
        
        for(auto it: directions)
        {
            int x = i + it.first;
            int y = j + it.second;
            
            if(x<0 || y<0 || x>=n || y>=m || visited[x][y]==1)
            {
                continue;
            }
            
           dfs(x,y,grid,visited,count,m,n);
        }
    }


    //Function to find unit area of the largest region of 1s.
    
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
      int max=0;
    int  m = grid[0].size();
    int  n = grid.size();
      vector<vector<bool>>visited(n,vector<bool>(m,0));
      
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(grid[i][j]==0)
              {
                  visited[i][j]=1;
              }
          }
      }
      
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(visited[i][j]==0)
              {
                  int count=0;
                  dfs(i,j,grid,visited,count,m,n);
                  
                  if(max<count)
                  max=count;
              }
          }
      }
      
      return max;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>>grid(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>grid[i][j];
            }
        }
        
        Solution obj;
        int ans = obj.findMaxArea(grid);
        cout<<ans<<"\n";
        
    }
    return 0;
}
