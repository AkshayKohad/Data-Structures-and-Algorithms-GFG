class Solution
{
    public:
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({grid[0][0],{0,0}});
        
        dist[0][0] = 0;
        
        while(pq.size()>0)
        {
            pair<int,pair<int,int>>cur = pq.top();
            pq.pop();
            
            int distance = cur.first;
            
            int i = cur.second.first;
            
            int j = cur.second.second;
            
            // if(i == n-1 && j == m-1)
            // continue;
            
            
            for(auto k : directions)
            {
                int x = i + k.first;
                
                int y = j + k.second;
                
                if(x>=n || y>=m || x<0 || y<0)
                continue;
                
                if(dist[x][y] > distance + grid[x][y])
                {
                    dist[x][y] = distance + grid[x][y];
                    
                    pq.push({distance + grid[x][y],{x,y}});
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};
