#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int binarySearch(int a[],int l,int r,int x)
    {
        int mid;
        while(l<r)
        {
            mid = (l+r)/2;
            if(a[mid]>x)
            {
                r=mid;
            }
           
             else if(a[mid]==x)
            return mid;
            
            else
            l=mid+1;
        }
        
        return r;
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        
        //  int tail[n]; 
        // int len =1; 
  
        // tail[0] = arr[0]; 
        
        // for (int i = 1; i < n; i++) {
            
        //     if(arr[i] > tail[len - 1])
        //     {
        //         tail[len] = arr[i];
        //         len++;
        //     }
        //     else{
        //         int c = ceilIdx(tail, 0, len - 1, arr[i]);
                
        //         tail[c] = arr[i];
        //     }
        // } 
        
       // your code here
       int lis[n];
       int len=1;
       lis[0]=a[0];
       
       for(int i=1;i<n;i++)
       {
           if(lis[len-1]<a[i])
           {
               lis[len]=a[i];
               len++;
           }
           
           else
           {
               int c = binarySearch(lis,0,len-1,a[i]);
               lis[c]=a[i];
           }
       }
       return len;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends
