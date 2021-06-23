class Solution{
public:

bool isSafe(int row,int col,int n,vector<vector<bool>>&visited)
{
    for(int i=0;i<col;i++)
    {
        if(visited[row][i]==true)
        return false;
        
    }
    
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(visited[i][j]==true)
        return false;
    }
    
    for(int i=row,j=col;i<n && j>=0;i++,j--)
    {
        if(visited[i][j]==true)
        return false;
    }
    
    return true;
}
void solution(int col,int n,vector<vector<bool>>&visited,vector<int>&b,vector<vector<int>>&a)
{
    if(col==n)
    {
        if(b.size()==n)
        a.push_back(b);
        
        return;
    }
    
    for(int i=0;i<n;i++)
    {
        if(isSafe(i,col,n,visited))
        {
            visited[i][col]=true;
            b.push_back(i);
            solution(col+1,n,visited,b,a);
            visited[i][col]=false;
            b.pop_back();
        }
    }
}
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>a;
        if(n==1)
        {
            a.push_back({1});
            return a;
            
        }
        
        if(n<=3)
        {
            return a;
            
        }
        
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        
        vector<int>b;
        
        solution(0,n,visited,b,a);
        
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[i].size();j++)
            a[i][j]=a[i][j]+1;
        }
        return a;
    }
};
