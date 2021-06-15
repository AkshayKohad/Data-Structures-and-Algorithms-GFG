#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    //code here
	    vector<bool>visited(V,0);
	    queue<pair<int,int>>q;
	    q.push({0,0});
	    visited[0]=true;
	    int level=0;
	    while(q.empty()==false)
	    {
	        pair<int,int>current=q.front();
	        q.pop();
	        level=current.second;
	        int s = current.first;
	        
	        if(s==X)
	        return level;
	        
	        for(auto u:adj[s])
	        {
	            if(visited[u]==false)
	            {
	                q.push({u,level+1});
	                visited[u]=true;
	            }
	        }
	    }
	    
	    return -1;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
