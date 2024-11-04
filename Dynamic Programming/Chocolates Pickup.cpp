class Solution {
  public:
  vector<pair<int,int>>directions = {{1,0},{1,-1},{1,1}};
    int maximum_chocolates(int r,int robot1_col,int robot2_col,int &n,int &m,vector<vector<int>>&grid,vector<vector<vector<int>>>&memo){
        if(r==n)return 0;
        
        if(memo[r][robot1_col][robot2_col]!=-1)return memo[r][robot1_col][robot2_col];
        
        int res = 0;
        for(auto k:directions){
            int robot1_col_new = robot1_col + k.second;
            
            if(robot1_col_new>=m || robot1_col_new<0)continue;
            
            for(auto l:directions){
                int robot2_col_new = robot2_col + l.second;
            
                if(robot2_col_new>=m || robot2_col_new<0)continue;
                
                if(robot2_col != robot1_col) res = max(res,grid[r][robot1_col]+grid[r][robot2_col]+maximum_chocolates(r+1,robot1_col_new,robot2_col_new,n,m,grid,memo));
                else res = max(res,grid[r][robot1_col]+maximum_chocolates(r+1,robot1_col_new,robot2_col_new,n,m,grid,memo));
            }
           
        }
        return memo[r][robot1_col][robot2_col] = res;
    }
    
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>>memo(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return maximum_chocolates(0,0,m-1,n,m,grid,memo);
    }
};
