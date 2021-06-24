bool isSafe(bool graph[101][101],int V,int i,int c,vector<int>&nodes)
{
    for(int j=0;j<V;j++)
    {
        if(graph[i][j]==1 && nodes[j]==c)
        return false;
        
    }
    return true;
}
bool solution(bool graph[101][101],int m,int V,vector<int>&nodes,int i)
{
    if(i==V)
    {
        return true;
    }
    
    for(int j=0;j<m;j++)
    {
        if(isSafe(graph,V,i,j,nodes))
        {
            nodes[i]=j;
            if(solution(graph,m,V,nodes,i+1))
            return true;
            nodes[i]=-1;
        }
    }
    return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    vector<int>nodes(V,-1);
   return solution(graph,m,V,nodes,0);
}
