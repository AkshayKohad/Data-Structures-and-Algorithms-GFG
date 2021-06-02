
class Solution 
{
    public:
    void dfs(vector<int> adj[],int s,bool visited[],vector<int>&a)
    {
        visited[s]=true;
        a.push_back(s);
        
        for(auto u : adj[s])
        {
            if(visited[u]==false)
            {
                dfs(adj,u,visited,a);
            }
        }
    }
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int>a;
	    // Code here
	    bool visited[V+1];
	    for(int i=0;i<V;i++)
	    {
	        visited[i]=false;
	    }
	    
	    dfs(adj,0,visited,a);
	    
	    return a;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  
