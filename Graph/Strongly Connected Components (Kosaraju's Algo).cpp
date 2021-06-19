class Solution
{
	public:
	
	void dfs(int s,vector<bool>&visited,vector<int>adj1[])
	{
	    visited[s]=true;
	    
	    for(auto u:adj1[s])
	    {
	        if(visited[u]==false)
	        dfs(u,visited,adj1);
	    }
	}

	void topological(int source,vector<bool>&visited,stack<int>&s,vector<int>adj[])
	{
	    visited[source]=true;
	    for(u:adj[source])
	    {
	        if(visited[u]==false)
	        topological(u,visited,s,adj);
	    }
	    s.push(source);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        
        vector<bool>visited(V,0);
        stack<int>s;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                topological(i,visited,s,adj);
            }
        }
        
        vector<int>adj1[V];
         visited.assign(V,0);
       
       for(int i=0;i<V;i++)
       {
           for(int j=0;j<adj[i].size();j++)
           {
               adj1[adj[i][j]].push_back(i);
           }
       }
       int count=0;
       while(s.empty()==false)
       {
           int curr = s.top();
           if(visited[curr]==false)
           {
               count++;
               dfs(curr,visited,adj1);   
           }
           s.pop();
       }
       
       return count;
    }
};
