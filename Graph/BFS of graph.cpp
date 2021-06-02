#include<bits/stdc++.h>
using namespace std;

 // } 



class Solution
{
    public:
    
    void bfs(vector<int>adj[],int s,bool visited[], vector<int>&a)
    {
        queue<int>q;
        q.push(s);
        visited[s]=true;
        
        while(q.empty()==false)
        {
            int u = q.front();
            q.pop();
            
            a.push_back(u);
            
            for( auto v:adj[u])
            {
                if(visited[v]==false)
                {
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
    }
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int>a;
	    // Code here
	    bool visited[V+1];
	    
	    for(int i=0;i<V;i++)
	    {
	        visited[i]=false;
	    }
	    
	  
	            bfs(adj,0,visited,a);
	        
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
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } 
