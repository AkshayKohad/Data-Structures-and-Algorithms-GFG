class Solution {
public:

vector<pair<int, int> > direction
    = { { 1, 0 }, { 0, -1 }, { -1, 0 }, { 0, 1 } };
    
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int n = hospital.size();
        
        int m = hospital[0].size();
        
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    
    queue<pair<pair<int, int>, int> > q;
   int uninfected_count=0;
   for(int i =0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           
           if(hospital[i][j]==2)
           {
               q.push({{i,j},0});
               visited[i][j]=1;
           }
           
           if(hospital[i][j]==1)
           {
               uninfected_count++;
           }
           
       }
   }
   
   int time = 0;
   
   while(q.empty()==false)
   {
       pair<pair<int,int>,int> current = q.front();
       q.pop();
       
       time = current.second;
       for(auto it: direction)
       {
           int  i = current.first.first + it.first;
           
            int j = current.first.second + it.second;
            
            
            if(i<0 || j<0 || i>=n || j>=m || hospital[i][j]!=1 || visited[i][j]!=0)
       continue;
       
       
         q.push({{i,j},time+1});
       visited[i][j]=1;
       uninfected_count--;
       }
       
   }
   
   if(uninfected_count!=0)
   return -1;
    
      
    
    return time;
    
        
    }
};
