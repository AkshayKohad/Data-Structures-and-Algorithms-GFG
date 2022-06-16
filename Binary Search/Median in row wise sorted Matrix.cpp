//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

  int count_num(int mid,vector<vector<int>>&matrix,int r,int c)
  {
      int count = 0;
    
      for(int i=0;i<r;i++)
      {
         int l = 0;
         int h = c-1;
         
         while(l<=h)
         {
             int m = (l+h)/2;
             if(mid>=matrix[i][m])
             {
                 l = m+1;
             }
             
             else{
                 h = m-1;
             }
         }
         count += l;
    
      }
      
      return count;
  }

    int median(vector<vector<int>> &matrix, int r, int c){
        // code here          
        
        int low = matrix[0][0];
        int high = matrix[0][0];
        
        for(int i=0;i<r;i++)
        {
            low = min(low,matrix[i][0]);
            high = max(high,matrix[i][c-1]);
        }
      
        int val = (r*c)/2;
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            int count = count_num(mid,matrix,r,c);
            //cout<<count<<endl;
            if(count<=val)
            {
                low = mid+1;
            }
            
            else{
                high = mid-1;
            }
        }
        
        return low;
    }
};


