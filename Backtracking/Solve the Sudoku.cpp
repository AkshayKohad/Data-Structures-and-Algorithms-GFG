class Solution 
{
    public:
    int isSafe(int col,int row,int val,int grid[N][N])
    {
        // if(grid[row][col]!=0)
        // return false;
    
       
        //int flag=0;
        for(int i=0;i<9;i++)
        {
            if(grid[i][col]==val)
            {
               return false;
            }
        }
        
        
        for(int j=0;j<9;j++)
        {
            if(grid[row][j]==val)
            {
                return false;
            }
        }
        
        
        
        int x = row/3;
        int y = col/3;
        int stx = 0 + x*3;
        
        int sty = 0 + y*3;
        
        
        int endx = 2 + x*3;
        
        int endy = 2 + y*3;
        
        //for(int i=stx,j=sty;i<=endx && j<=endy; )
        for(int i=stx;i<=endx;i++)
        {
            for(int j=sty;j<=endy;j++)
            {
                if(grid[i][j]==val)
                {
                return false;
                }
                
            }
            
            
        }
        
       
        
        return true;
        
        
    }
    bool solution(int grid[N][N],vector<pair<int,int>>&p,int count)
    {
        if(count==p.size())
        return true;
        
        
            int x = p[count].first;
            int y = p[count].second;
            
            for(int j=1;j<=9;j++)
               { 
                if(isSafe(y,x,j,grid))
                {
                    grid[x][y]=j;
                   
                   if(solution(grid,p,count+1))
                    return true;
                    grid[x][y]=0;
                }
               }
       
         
        return false;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        vector<pair<int,int>>p;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(grid[i][j]==0)
                p.push_back({i,j});
            }
        }
        // Your code here
        int count=0;
        return solution(grid,p,count);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            
        }
    }
};
