#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    vector<pair<int,int>>directions = {{2,1},{2,-1},{-2,-1},{-2,1},{1,2},{-1,2},{-1,-2},{1,-2}};
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    vector<vector<bool>>visited(N,vector<bool>(N,0));
	    
	    queue<pair<pair<int,int>,int>>q;
	    
	    int i = TargetPos[0]-1;
	    int j = TargetPos[1]-1;
	    
	    q.push({{KnightPos[0]-1,KnightPos[1]-1},0});
	    int moves = 0;
	    
	    visited[KnightPos[0]-1][KnightPos[1]-1]==1;
	    while(q.empty()==false)
	    {
	        pair<pair<int,int>,int>current = q.front();
	        q.pop();
	        moves = current.second;
	        if(current.first.second == j && current.first.first == i)
	        {
	            flag=1;
	        
	        return moves;
	        }
	          
	        for(auto it : directions)
	        {
	            int x = current.first.first + it.first;
	            int y = current.first.second + it.second;
	            
	            if(x<0 || y<0 || x>=N || y>=N || visited[x][y]==1)
	            continue;
	          
	         
	            q.push({{x,y},moves+1});
	            visited[x][y]=1;
	            
	        }
	    }
	    
	 
	    return -1;
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  
