class Solution
{
    public:
    
    void dfs(int i,int j, bool *visited,vector<vector<char>>&grid)
    {
        *(visited + grid[0].size()*i +j) = true;
         
         if(i-1>=0)
         {
             if(*(visited + grid[0].size()*(i-1) +j)==false)
             {
                 dfs(i-1,j,visited,grid);
             }
         }
         
         if(i+1<grid.size())
         {
             if(*(visited + grid[0].size()*(i+1) +j)==false)
             {
                 dfs(i+1,j,visited,grid);
             }
         }
         
         if(j-1>=0)
         {
             if(*(visited + grid[0].size()*(i) +(j-1))==false)
             {
                 dfs(i,j-1,visited,grid);
             }
         }
         
         if(j+1<grid[0].size())
         {
             if(*(visited + grid[0].size()*(i) +(j+1))==false)
             {
                 dfs(i,j+1,visited,grid);
             }
         }
    }
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        bool visited[grid.size()][grid[0].size()];
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='O')
                {
                    visited[i][j]=true;
                }
                
                else{
                    visited[i][j]=false;
                }
            }
            
        }
        int count=0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(visited[i][j]==false)
                {
                    dfs(i,j,&visited[0][0],grid);
                    count++;
                }
                
            }
        }
        
        return count;
    }
};
