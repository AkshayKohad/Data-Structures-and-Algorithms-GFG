class Solution{
public:
bool isSafe(vector<int>&b,int l)
{
    if(b.size()==0)
    return true;
    
    if(b[b.size()-1]==l+1 || b[b.size()-1]==l-1)
    return false;
    
    return true;
}

void solution(int n,vector<bool>&visited,vector<int>&b,vector<vector<int>>&a,int &count,int l)
{
    
    
    int j = l;
     vector<int>c;
    if(visited[j]==false)
    {
        c.push_back(j);
    }
   
    j=(j+1)%n;
    while(j!=l)
    {
       if(visited[j]==false)
       {
        c.push_back(j);
       }
        j=(j+1)%n;
    }
        for(int i=0;i<c.size();i++)
        {
        
           if(isSafe(b,c[i]))
           {
               b.push_back(c[i]);
               visited[c[i]]=true;
             //  count++;
               solution(n,visited,b,a,count,c[i]);
               b.pop_back();
               visited[c[i]]=false;
               //count--;
           }
        }
        if(b.size()==n)
     a.push_back(b);
        }
   

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>a;
        if(n==1)
        {
            a.push_back({1});
        return a;
        }
        if(n<=3)
        {
          
        return a;
        }
        
        vector<bool>visited(n,0);
        vector<int>b;
        int count=0;
        solution(n,visited,b,a,count,0);
        
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[i].size();j++)
            a[i][j]=a[i][j]+1;
        }
        return a;
    }
};
