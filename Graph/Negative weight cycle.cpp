#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    
	  //  cout<<edges[0][0]<<","<<edges[0][1]<<" -> "<<edges[0][2]<<endl;
	    vector<int>dist(n,INT_MAX);
	    dist[0]=0;
	    for(int i=0;i<n-1;i++)
	    {
	        for(int j=0;j<edges.size();j++)
	        {
	            int u = edges[j][0];
	            int v = edges[j][1];
	            int len = edges[j][2];
	            if(dist[u]!=INT_MAX && dist[v]>dist[u]+len)
	            {
	                dist[v]=dist[u]+len;
	            }
	        }
	    }
	    
	    for(int j=0;j<edges.size();j++)
	    {
	        int u = edges[j][0];
	            int v = edges[j][1];
	            int len = edges[j][2];
	            if(dist[u]!=INT_MAX && dist[v]>dist[u]+len)
	            {
	                return 1;
	            }
	    }
	    
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
