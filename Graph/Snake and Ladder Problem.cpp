// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

 vector<int>dice = {1,2,3,4,5,6};
    int minThrow(int n, int arr[]){
        // code here
        unordered_map<int,int>ladder,snake;
        for(int i=0;i<2*n-1;i=i+2)
        {
            if(arr[i]<arr[i+1])
            {
                ladder[arr[i]] = arr[i+1];
                
            }
            
            else
            {
                snake[arr[i]] = arr[i+1];
            }
            
            
        }
        
        // for(auto x : ladder)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
     
     
        // for(auto x : snake)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
     
        
        queue<pair<int,int>>q;
        q.push({1,0});
        int min = -1;
        while(q.empty()==false)
        {
          pair<int,int>ans = q.front();
           q.pop();
          int moves = ans.second;
          for(auto res : dice)
          {
              int x = ans.first;
              x = x+res;
               
               if(x==30)
               return moves+1;
               
                   
               
               if(ladder.find(x)!=ladder.end())
              {
                  x=ladder[x];
                    if(x==30)
                  {
                       
                      return moves+1;
                  }
                   
              
              }
               
              else if(snake.find(x)!=snake.end())
              {
                 
                    if(x==30)
                  {
                       
                      return moves+1;
                  }
                   
                   x = snake[x];
                     
              }
              
               
                  //cout<<x<<endl;
                  q.push({x,moves+1});
                  
               
               
          }
           
        }
        
        return min;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
