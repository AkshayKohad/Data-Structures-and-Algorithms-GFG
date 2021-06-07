class Solution 
{
    public:
    bool dfs(vector<int>adj[],int s,bool visited[],int parent)
    {
        visited[s]=true;
        
        for(auto u : adj[s])
        {
            if(visited[u]==false)
            {
                if(dfs(adj,u,visited,s)==true)
                return true;
            }
            
            else if(u!=parent)
            return true;
        }
        
        return false;
    }
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    bool visited[V];
	    
	    for(int i=0;i<V;i++)
	    {
	        visited[i]=false;
	    }
	    
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==false)
	        {
	            if(dfs(adj,i,visited,-1)==true)
	            return true;
	        }
	    }
	    return false;
	}
};
