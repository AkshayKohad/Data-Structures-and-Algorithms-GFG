class Solution{
    public:
    static bool mycmp(string &a,string &b)
    {
        int k;
        if(a.size()>b.size())
        {
            k=b.size();
        }
        else
        k=a.size();
        
        for(int i=0;i<k;i++)
        {
            if(a[i]==b[i])
            continue;
            
            return a[i]<b[i];
        }
    }
     vector<pair<pair<int,int>,char>>directions = {{{0,1},'R'},{{1,0},'D'},{{0,-1},'L'},{{-1,0},'U'}};
     
     bool check(int x,int y,int n,vector<vector<bool>>&visited,vector<vector<int>>&m)
     {
         if(x<0 || y<0 || x>=n || y>=n || visited[x][y]==true)
         return false;
         
         return true;
     }
    void solution(int i,int j,int n,vector<vector<int>>&m,vector<vector<bool>>&visited,string &a, vector<string>&b)
    {
        visited[i][j]=true;
        
        if(i==n-1 && j==n-1)
        {
            if(a.size()!=0)
            {
                b.push_back(a);
                // a.pop_back();
            }
           visited[i][j]=false;
            return;
        }
        for(auto u:directions)
        {
            int x = i + u.first.first;
            int y = j + u.first.second;
            
            if(check(x,y,n,visited,m)==false)
            continue;
            
            a.push_back(u.second);
            solution(x,y,n,m,visited,a,b);
            a.pop_back();
        }
        
        visited[i][j]=false;
        
    }
   
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        string a;
        vector<string>b;
        if(m[0][0]==0)
        {
            b.push_back("-1");
            return b;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(m[i][j]==0)
                visited[i][j]=true;
            }
        }
        solution(0,0,n,m,visited,a,b);
        
        if(b.size()==0)
        {
             b.push_back("-1");
            return b;
        }
        sort(b.begin(),b.end(),mycmp);
        return b;
    }
};

    
