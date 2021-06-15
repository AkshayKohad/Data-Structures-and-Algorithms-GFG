class Solution
{
    public:
  	void countPathsUtil(vector<int> *adj, int u, int d, vector<bool> &visited,
                    int &pathCount)
    {
        //marking the current vertex as visited.
        visited[u] = true; 
        
        //if current node is equal to destination node, we increase the count.
        if (u == d)
            pathCount++;
        else 
        {
            vector<int>::iterator i;
            //traversing over the adjacent vertices.
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            
                //if any vertex is not visited, we call the function  
                //recursively for adjacent node.
                if (!visited[*i]) 
                    countPathsUtil(adj, *i, d, visited, pathCount);
        }
        //marking the current vertex as not visited.
        visited[u] = false; 
    }
    
    //Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination)
    {
        //using boolean array to mark visited nodes and currently 
        //marking all the nodes as false.
        vector<bool> visited(V + 1, false);
    
        int pathCount = 0;
        
        //calling the function to count paths
        countPathsUtil(adj, source, destination, visited, pathCount);
        return pathCount;
    }   
};
