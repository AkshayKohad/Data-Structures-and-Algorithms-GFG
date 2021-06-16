class Solution 
{
    public:
    
    void solution(int s,vector<bool>&visited,vector<int>adj[])
    {
        visited[s]=true;
    
        
        for(auto u : adj[s])
        {
            if(visited[u]==false)
            solution(u,visited,adj);
        }
    }
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	     vector<bool>visited(V,0);
	     int v;
	    // Code here
	    for(int i=0;i<V;i++)
	    {
	       
	        
	        if(visited[i]==false)
	        {
	        solution(i,visited,adj);
	        v=i;
	        }
	        
	    }
	    
	    visited.assign(V,0);
	    
	    solution(v,visited,adj);
	    
	    for(auto i : visited)
	    {
	        if(!i)
	        return -1;
	    }
	    return v;
	}

};
