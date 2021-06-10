class Solution {
  public:
  vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        
        vector<vector<bool>>visited(N,vector<bool>(M,0));
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(A[i][j]==0)
                {
                    visited[i][j]=1;
                }
            }
        }
        
        queue<pair<pair<int,int>,int>>q;
        if(A[0][0]==1)
        q.push({{0,0},0});
        int moves=0;
        while(q.empty()==false)
        {
            pair<pair<int,int>,int>current = q.front();
            q.pop();
            moves = current.second;
            
            if(current.first.first == X && current.first.second == Y)
            return moves;
            
            for(auto it : directions)
            {
                int x = it.first + current.first.first;
                int y = it.second + current.first.second;
                
                if(x<0 || y<0 || x>=N || y>=M || visited[x][y]!=0)
                continue;
                
                q.push({{x,y},moves+1});
                visited[x][y]=1;
            }
        }
        return -1;
    }
};
