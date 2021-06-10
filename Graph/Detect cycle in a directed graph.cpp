class Solution
{
    public:
    bool dfs(int s,vector<int> adj[],vector<bool>&visited,vector<bool>&recursion)
    {
        visited[s]=true;
        recursion[s]=true;
        
        for(auto u:adj[s])
        {
            if(visited[u]==false && dfs(u,adj,visited,recursion)==true)
            return true;
            
            else if(recursion[u]==true)
            return true;
        }
        recursion[s]=false;
        return false;
    }
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	 vector<bool>visited(V,0);
	 vector<bool>recursion(V,0);
	 
	 for(int i=0;i<V;i++)
	 {
	     if(visited[i]==0)
	     {
	         if(dfs(i,adj,visited,recursion)==true)
	         return true;
	     }
	 }
	 
	 return false;
	   	// code here
	}
};
