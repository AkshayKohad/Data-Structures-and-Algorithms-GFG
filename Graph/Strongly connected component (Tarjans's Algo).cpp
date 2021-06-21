#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:

	static bool mycmp(const vector<int>&v1,const vector<int>&v2)
	{
	    return v1[0]<v2[0];
	}
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

	void solution1(vector<int>adj[],int s,vector<bool>&visited,vector<int>&ldis,vector<int>&dis,vector<bool>&visitedstack,stack<int>&st,vector<vector<int>>&a)
	{
	    visited[s]=true;
        st.push(s);
        visitedstack[s]=true;
	    for(auto u : adj[s])
	    {
	        if(visited[u]==false)
            {
	        solution1(adj,u,visited,ldis,dis,visitedstack,st,a);
	         if(ldis[s]>ldis[u])
	        ldis[s]=ldis[u];
            }

	        else if(visited[u]==true && visitedstack[u]==true)
	        {
	            if(ldis[s]>ldis[u])
	            ldis[s]=ldis[u];
	        }


	    }
	    
	    if(dis[s]==ldis[s])
	    {
	        vector<int>c;
	        while(st.top()!=s)
	        {
	            c.push_back(st.top());
	            visitedstack[st.top()]=false;
	            st.pop();
	        }
	        c.push_back(st.top());
	        visitedstack[st.top()]=false;
	        st.pop();
	        a.push_back(c);
	        c.clear();
	    }
	}
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        vector<vector<int>>a;
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
        vector<bool>visitedstack(V,0);
        stack<int>st;
        for(int i=0;i<V;i++)
        {
        if(visited[i]==false)
        {    
        solution1(adj,i,visited,ldis,dis,visitedstack,st,a);
        }

        }
        
        for(int i=0;i<a.size();i++)
        sort(a[i].begin(),a[i].end());
        
        sort(a.begin(),a.end(),mycmp);
        return a;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
