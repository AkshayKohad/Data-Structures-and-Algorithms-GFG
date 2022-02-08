

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:

int solve(int mask,int pos,int visited_all,vector<vector<int>>cost,vector<vector<int>>&memo)
{
    if(mask == visited_all)
    {
        return cost[pos][0];
    }
    
    if(memo[mask][pos]!=-1)
    return memo[mask][pos];
    
    int ans = INT_MAX;
    int n = cost.size();
    for(int city = 0;city<n;city++)
    {
        if((mask&(1<<city))==0)
        {
            int res = cost[pos][city] + solve(mask | (1<<city),city,visited_all,cost,memo);
            ans = min(ans,res);
        }
    }
    
    return memo[mask][pos]=ans;
}


int total_cost(vector<vector<int>>cost){
    // Code here
    int mask = 1;
    int pos = 0;
    int n = cost.size();
    int visited_all = pow(2,n)-1;
    
    vector<vector<int>>memo((1<<n),vector<int>(n,-1));
    return solve(mask,pos,visited_all,cost,memo);
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
