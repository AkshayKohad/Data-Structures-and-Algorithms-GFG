// User function Template for C++

class Solution {
  public:
  
  vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
  int find(int i,vector<int>&parent)
    {
        if(parent[i]==-1)
        return i;
        
        return parent[i] = find(parent[i],parent);
    }
    
    void unite(int par,int par1,vector<int>&parent,vector<int>&rank)
    {
        if(rank[par]>=rank[par1])
        {
            rank[par]+=rank[par1];
            parent[par1] = par;
        }
        else{
             rank[par1]+=rank[par];
            parent[par] = par1;
        }
    }
  
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int>parent(n*m,-1);
        vector<int>rank(n*m,1);
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                continue;
                
                
                visited[i][j] = 1;
                int res = i*m + j;
                
                int par = find(res,parent);
                
               for(auto k:directions)
               {
                int x_new = i+k.first;
                int y_new = j+k.second;
                
                if(x_new <0 || y_new<0 || x_new>= n || y_new>=m || grid[x_new][y_new]==0)
                continue;
                
                int res_new = x_new*m + y_new;
                
                int par1 = find(res_new,parent);
                
                if(par!=par1)
                {
                    
                    
                    unite(par,par1,parent,rank);
                }
                
                 par = find(res,parent);
               }
            }
        }
        
        int result = 0;
        
        for(int i=0;i<parent.size();i++)
        {
           if(parent[i]==-1)
           {
               result = max(result,rank[i]);
           }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==1)continue;
                
                int count = 0;
                
                unordered_set<int>s;
                for(auto k:directions)
                {
                    int x = i+k.first;
                    int y = j+k.second;
                    
                    if(x <0 || y<0 || x>= n || y>=m || grid[x][y]==0)
                     continue;
                    
                    int res = x*m + y;
                    
                    int par = find(res,parent);
                    
                    if(s.find(par)==s.end())
                    {
                        count += rank[par];
                        s.insert(par);
                    }
                    
                     
                }
                
                result = max(result,count+1);
            }
        }
        
        return result;
        
    }
};
