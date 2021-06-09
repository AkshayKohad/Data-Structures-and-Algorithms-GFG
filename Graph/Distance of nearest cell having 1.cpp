#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    int distance = 0;
	    
	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({{i,j},0});
	                grid[i][j]=-1;
	            }
	        }
	    }
	    
	    while(q.empty()==false)
	    {
	        pair<pair<int,int>,int>current = q.front();
	        q.pop();
	        distance = current.second;
	        for(auto it:directions)
	        {
	            int x = current.first.first + it.first;
	            int y =  current.first.second + it.second;
	            
	            if(x<0 || y<0 || x>=n || y>=m || grid[x][y]!=0)
	            continue;
	            
	            q.push({{x,y},distance+1});
	            grid[x][y]=distance+1;
	        }
	        
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==-1)
	            grid[i][j]=0;
	        }
	    }
	    
	    return grid;
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends
