#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>a(V,INT_MAX);
        a[S]=0;
        queue<pair<int,int>>q;
        q.push({S,0});
        while(q.empty()==false)
        {
            pair<int,int>current = q.front();
            q.pop();
            int path = current.second;
            int s = current.first;
            for(int i=0;i<adj[s].size();i++)
            {
                if(adj[s][i][1]+path<a[adj[s][i][0]])
                {
                    a[adj[s][i][0]]=adj[s][i][1]+path;
                    q.push({adj[s][i][0],a[adj[s][i][0]]});
                }
            }
        }
        return a;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
