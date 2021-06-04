class Solution
{
  
  
    public:
    
    void solution1(int i,int j,bool *visited,vector<vector<char>>&grid)
    {
        *(visited + grid[0].size()*i +j) = true;
        
        int i1 = i;
        int j1 = j;
        
         if(i1-1>=0)
       {
            if(*(visited + grid[0].size()*(i1-1) + j1)==false)
            {
            
               solution1(i1-1,j1,visited,grid);
            }
            
           if(j1-1>=0)
           {
               if(*(visited + grid[0].size()*(i1-1) + (j1-1))==false)
               {
               
               solution1(i1-1,j1-1,visited,grid);
               }
              
           }
           
           if(j1+1<grid[0].size())
           {
                if(*(visited + grid[0].size()*(i1-1) + (j1+1))==false)
               {
              
               solution1(i1-1,j1+1,visited,grid);
               }
           }
           
       }
       
       if(j1-1>=0)
       {
           
           if(*(visited + grid[0].size()*i1 + (j1-1))==false)
           {
              
               solution1(i1,j1-1,visited,grid);
           }
       }
       
       if(j1+1<grid[0].size())
       {
            if(*(visited + grid[0].size()*i1 + (j1+1))==false)
            {
               
               solution1(i1,j1+1,visited,grid);
            }
       }
       
       if(i1+1<grid.size())
       {
            if(*(visited + grid[0].size()*(i1+1) + j1)==false)
            {
              
               solution1(i1+1,j1,visited,grid);
            }
            
            if(j1-1>=0)
            {
                 if(*(visited + grid[0].size()*(i1+1) + (j1-1))==false)
                {
                 
                 solution1(i1+1,j1-1,visited,grid);
               }
            }
            
            if(j1+1<grid[0].size())
            {
              if(*(visited + grid[0].size()*(i1+1) + (j1+1))==false)
               {
              
               solution1(i1+1,j1+1,visited,grid);
               }
            }
       }
       
    }
    
    void solution(int i,int j,bool *visited,vector<vector<char>>&grid)
    {
      
       queue<int>q;
       queue<int>q1;
       q.push(i);
       q1.push(j);
       
       while(q.empty()==false && q1.empty()==false)
       {
           int i1 = q.front();
           int j1 = q1.front();
           q.pop();
           q1.pop();
       *(visited + grid[0].size()*i1 + j1) = true;
       
       if(i1-1>=0)
       {
            if(*(visited + grid[0].size()*(i1-1) + j1)==false)
            {
            q.push(i1-1);
               q1.push(j1);
            }
            
           if(j1-1>=0)
           {
               if(*(visited + grid[0].size()*(i1-1) + (j1-1))==false)
               {
               q.push(i1-1);
               q1.push(j1-1);
               }
              
           }
           
           if(j1+1<grid[0].size())
           {
                if(*(visited + grid[0].size()*(i1-1) + (j1+1))==false)
               {
               q.push(i1-1);
               q1.push(j1+1);
               }
           }
           
       }
       
       if(j1-1>=0)
       {
           
           if(*(visited + grid[0].size()*i1 + (j1-1))==false)
           {
               q.push(i1);
               q1.push(j1-1);
           }
       }
       
       if(j1+1<grid[0].size())
       {
            if(*(visited + grid[0].size()*i1 + (j1+1))==false)
            {
               q.push(i1);
               q1.push(j1+1);
            }
       }
       
       if(i1+1<grid.size())
       {
            if(*(visited + grid[0].size()*(i1+1) + j1)==false)
            {
               q.push(i1+1);
               q1.push(j1);
            }
            
            if(j1-1>=0)
            {
                 if(*(visited + grid[0].size()*(i1+1) + (j1-1))==false)
                {
                 q.push(i1+1);
                 q1.push(j1-1);
               }
            }
            
            if(j1+1<grid[0].size())
            {
              if(*(visited + grid[0].size()*(i1+1) + (j1+1))==false)
               {
               q.push(i1+1);
               q1.push(j1+1);
               }
            }
       }
       
       }
       
    }
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
    
        bool visited[grid.size()][grid[0].size()];
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='0')
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
                    solution1(i,j,&visited[0][0],grid);
                    count++;
                }
            }
        }
        
        return count;
    }
};
