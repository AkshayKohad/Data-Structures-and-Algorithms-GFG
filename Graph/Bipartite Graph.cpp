#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

bool dfs(vector<int>adj[],int src,int parent,vector<int>&visited,int color)
    {
        visited[src]=color;
        for(auto x : adj[src])
        {
            if(visited[x]==0)
            {
                bool res = dfs(adj,x,src,visited,3-color);
                if(res==false)
                    return false;
            }
            
            else{
                if(x!=parent)
                {
                    if(visited[x]==visited[src])
                        return false;
                }
            }
        }
        
        return true;
    }
    

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	     int n = V;
        vector<int>visited(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
              
                if( dfs(adj,i,-1,visited,1)==false)
                    return false;
            }
        }
        return true;
	    
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
