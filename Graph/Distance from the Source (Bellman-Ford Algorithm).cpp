class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int s) {
        // Code here
        int inf = 100000000;
        
        vector<int>dist(V,inf);
        
        dist[s] = 0;
        
        for(int i=1;i<V;i++)
        {
            
        for(int j=0;j<adj.size();j++)
        {
           int x = adj[j][0];
           int y = adj[j][1];
           
           int wt = adj[j][2];
           
           if(dist[x]+wt<dist[y])
           dist[y] = dist[x] + wt;
        }
        
        }
        
        return dist;
        
        
    }
};
