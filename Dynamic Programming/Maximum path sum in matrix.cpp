class Solution{
public:


    vector<pair<int,int>>directions = {{1,0},{1,-1},{1,1}};
    
    int solve(int i,int j,int &n,vector<vector<int>>&matrix,vector<vector<int>>&memo)
    {
        if(i==n-1)
        {
            return matrix[i][j];
        }
        
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        int result = INT_MIN;
        for(auto k:directions)
        {
            int x = i+k.first;
            
            int y = j+k.second;
            
            if(x<0 || y<0 || x>=n || y>=n)
            continue;
            
            int ans = matrix[i][j] + solve(x,y,n,matrix,memo);
            
            result = max(result,ans);
        }
        
        return memo[i][j] = result;
    }
    
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        // code here
        
        int res = INT_MIN;
        
        vector<vector<int>>memo(n,vector<int>(n,-1));
        for(int col=0;col<n;col++)
        res = max(res,solve(0,col,n,matrix,memo));
        
        
        return res;
        
    }
};
