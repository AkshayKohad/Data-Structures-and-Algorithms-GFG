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
     // cout<<"m "<<mid<<endl;
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
        // cout<<l<<endl;
         count += l;
        // cout<<"f "<<l<<endl;
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
      //  cout<<low<<" "<<high<<endl;
      //  int low = 1;
    //    int high = 1e9;
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

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends
