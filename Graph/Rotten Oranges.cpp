class Solution 
{
    public:
    vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        
        queue<pair<pair<int, int>, int> > q;
        int unrotten_count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    visited[i][j]=1;
                    q.push({{i,j},0});
                }
                
                if(grid[i][j]==1)
                unrotten_count++;
            }
        }
        
        int time = 0;
        while(q.empty()==false)
        {
            pair<pair<int,int>,int>current = q.front();
            q.pop();
            
            time = current.second;
            
            for(auto it : directions)
            {
                int i = it.first + current.first.first;
                
                int j = it.second + current.first.second;
                
                if(i<0 || j<0 || i>=n || j>=m || visited[i][j]!=0 || grid[i][j]!=1)
                continue;
                
                q.push({{i,j},time+1});
                visited[i][j]=1;
                unrotten_count--;
            }
        }
        
        if(unrotten_count!=0)
        return -1;
        
        return time;
    }
};
