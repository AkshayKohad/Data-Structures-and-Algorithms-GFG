class Solution
{
    public:
    
    void dfs(int i,int j,int *visited,vector<vector<int>>&grid,bool &flag)
    {
        if(*(visited + grid[0].size()*i + j)==2)
        {
            flag=true;
            return;
        }
        
        *(visited + grid[0].size()*i + j)=1;
        
        if(i-1>=0)
        {
            if(*(visited + grid[0].size()*(i-1) + j)!=1)
            {
            dfs(i-1,j,visited,grid,flag);
            }
        }
        
        if(i+1<grid.size())
        {
             if(*(visited + grid[0].size()*(i+1) + j)!=1)
            {
            dfs(i+1,j,visited,grid,flag);
            }
        }
        
        if(j-1>=0)
        {
             if(*(visited + grid[0].size()*(i) + (j-1))!=1)
            {
            dfs(i,j-1,visited,grid,flag);
            }
        }
        
        if(j+1<grid[0].size())
        {
             if(*(visited + grid[0].size()*(i) + (j+1))!=1)
            {
            dfs(i,j+1,visited,grid,flag);
            }
        }
        
        
        
    }
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        if(grid.size()==1 && grid[0].size()==1)
        return false;
        
        int visited[grid.size()][grid[0].size()];
        int di=-1,dj=-1;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    di=i;
                    dj=j;
                    visited[i][j]=0;
                }
                
                else if(grid[i][j]==2)
                {
                    visited[i][j]=2;
                }
                
                else if(grid[i][j]==3)
                {
                    visited[i][j]=0;
                }
                
                else{
                    visited[i][j]=1;
                }
            }
        }
        
        if(di==-1 && dj==-1)
        return false;
        
        bool flag = false;
        dfs( di, dj,&visited[0][0],grid,flag);
        
        return flag;
    }
};
