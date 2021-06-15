#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	
	void dfs(int s,vector<int> adj[],vector<bool>&visited,vector<int>&a,vector<int>&count)
	{
	    for(auto u: adj[s])
	    {
	        if(count[u]==0 && visited[u]==false)
	        {
	            //cout<<" count of "<<u<<" is "<< count[u]<<endl;
	            if(visited[u]==false)
	             {
	                 a.push_back(u);
	                 visited[u]=true;
	             }
	             
	             dfs(u,adj,visited,a,count);
	        }
	        
	        else if(count[u]>0)
	        {
	            count[u]--;
	            // cout<<" count of "<<u<<" is "<< count[u]<<endl;
	         if(count[u]==0)
	           {
	            if(visited[u]==false)
	             {
	                 a.push_back(u);
	                // cout<<" printed value is "<<u<<endl;
	                 visited[u]=true;
	                  dfs(u,adj,visited,a,count);
	             }
	             
	            
	           }
	            
	        }
	    }
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>count(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto u : adj[i])
	        {
	            count[u]++;
	        }
	    }
	   // for(int i=0;i<count.size();i++)
	   // cout<<count[i]<<" ";
	   // cout<<endl;
	    vector<bool>visited(V,0);
	    vector<int>a;
	    for(int i=0;i<V;i++)
	    {
	        if(count[i]==0)
	        {
	            if(visited[i]==false)
	            {
	            a.push_back(i);
	             visited[i]=true;
	             dfs(i,adj,visited,a,count);
	           //  cout<<" printed value is "<<i<<endl;
	            }
	           
	            
	        }
	    }
	   // for(int i=0;i<a.size();i++)
	   // cout<<a[i]<<" ";
	    
	   // cout<<endl;
	    return a;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
