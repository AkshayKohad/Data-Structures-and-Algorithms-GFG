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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
        
        
        vector<int>parent(n*m,-1);
        
        vector<int>rank(n*m,1);
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        int islands_count = 0;
        
        int sz = operators.size();
        
        
        vector<int>result;
        
        
        for(int i=0;i<sz;i++)
        {
            int x = operators[i][0];
            int y = operators[i][1];
            
            if(visited[x][y]==1)
            {
                result.push_back(islands_count);
                continue;
            }
            
            visited[x][y] = 1;
            
            int res = x*m + y;
            
            int par = find(res,parent);
            
            islands_count+=1;
            
            for(auto k:directions)
            {
                int x_new = x+k.first;
                int y_new = y+k.second;
                
                if(x_new <0 || y_new<0 || x_new>= n || y_new>=m || visited[x_new][y_new]==0)
                continue;
                
                int res_new = x_new*m + y_new;
                
                int par1 = find(res_new,parent);
                
                if(par!=par1)
                {
                    islands_count -=1;
                    
                    unite(par,par1,parent,rank);
                }
                
                par = find(res,parent);
            }
            
           result.push_back(islands_count);
        }
        
        return result;
    }
};
