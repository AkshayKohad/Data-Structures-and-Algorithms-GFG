class Solution
{
	public:
	struct vertices{
	  int index;
	  int val;
	};
	struct mycmp{
	  bool operator() (pair<int,int> &a, pair<int,int>&b)
	  {
	     return a.second>b.second;
	  }
	};
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<bool>visited(V,0);
        vector<int>minSpan(V,INT_MAX);
        minSpan[0]=0;
        int res=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycmp>pq;
        // pq.push({2,1});
        // pq.push({0,3});
        // pq.push({5,5});
        for(int i=0;i<V;i++)
        {
            pq.push({i,minSpan[i]});
        }
        
        for(int count=0;count<V;count++)
        {
            while(visited[pq.top().first]==true)
            {
                pq.pop();
            }
            visited[pq.top().first]=true;
            res = res+minSpan[pq.top().first];
            int u = pq.top().first;
            for(int i=0;i<adj[u].size();i++)
            {
                if(visited[adj[u][i][0]]==false)
                {
                    if(adj[u][i][1]<minSpan[adj[u][i][0]])
                    {
                        pq.push({adj[u][i][0],adj[u][i][1]});
                        minSpan[adj[u][i][0]]=adj[u][i][1];
                    }
                }
            }
            
        }
        return res;
        
    }
};
