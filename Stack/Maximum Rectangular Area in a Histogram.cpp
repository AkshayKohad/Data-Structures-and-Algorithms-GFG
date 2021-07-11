#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array
long getMaxArea(long long a[], int n){
    
    // Your code here 
    
    vector<int>right;
    vector<int>left;
    vector<long long>res;
    left.push_back(1);
    
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            left.push_back(1);
        }
        
        else{
            int f=left.size()-1;
            int count=0;
            while(f>=0 && a[f]>=a[i])
            {
                count=count+left[f];
                f=f-left[f];
                
            }
            left.push_back(count+1);
        }
    }
    
    int t;
    int i=0;
    int j=n-1;
    while(i<j)
    {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
        i++;
        j--;
    }
   
   right.push_back(1);
     for(int i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            right.push_back(1);
        }
        
        else{
            int f=right.size()-1;
            int count=0;
            while(f>=0 && a[f]>=a[i])
            {
                count=count+right[f];
                f=f-right[f];
                
            }
            right.push_back(count+1);
        }
    }
    
   
    long long max=-1;
    // for(i=0;i<n;i++)
    // {
    //     cout<<left[i]<<" ";
    // }
    // cout<<endl;
    //  for(i=n-1;i>=0;i--)
    // {
    //     cout<<right[i]<<" ";       //starting from n-1 because we have reversed the array 'a'
    //                                 // for right array
    // }
    // cout<<endl;
     for(i=0;i<n;i++)
     {
         if(max<(a[n-i-1]*(left[i]+right[n-1-i]-1)))
         max=a[n-i-1]*(left[i]+right[n-1-i]-1);
     }
    
    return max;
    
}

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout<<getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
