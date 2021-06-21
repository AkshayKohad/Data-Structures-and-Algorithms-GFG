class Solution
{
	public:
	
	void solution(int s,vector<int>&dis,vector<int>adj[],vector<bool>&visited,int &count)
	{
	    visited[s]=true;
	    dis[s]=count;
	    count++;
	    for(auto u:adj[s])
	    {
	        if(visited[u]==false)
	        {
	            solution(u,dis,adj,visited,count);
	        }
	    }
	}
	
	void solution1(vector<int>adj[],int s,vector<bool>&visited,int parent,vector<int>&ldis)
	{
	    visited[s]=true;
	    
	    for(auto u : adj[s])
	    {
	        if(visited[u]==false)
            {
	        solution1(adj,u,visited,s,ldis);
	         if(ldis[s]>ldis[u])
	        ldis[s]=ldis[u];
            }
	        
	        else if(visited[u]==true && parent!=u)
	        {
	            if(ldis[s]>ldis[u])
	            ldis[s]=ldis[u];
	        }
	        
	       
	    }
	}
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int>dis(V,0);
        vector<int>ldis(V,0);
        vector<bool>visited(V,0);
        
        for(int i=0;i<V;i++)
        {
            int count=1;
        if(visited[i]==false)
        solution(i,dis,adj,visited,count);
        }
        
        for(int i=0;i<V;i++)
        {
            ldis[i]=dis[i];
        }
        visited.assign(V,0);

        for(int i=0;i<V;i++)
        {
        if(visited[i]==false)
        {    
        solution1(adj,i,visited,-1,ldis);
        }
        
       
        }
        
        
        if(ldis[c]>dis[d] || ldis[d]>dis[c])
        return 1;
        
        
        
       
        
        return 0;
    }
};
