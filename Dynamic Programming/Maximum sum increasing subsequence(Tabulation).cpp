#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int a[], int n)  
	{  
	    // Your code goes here
	    int sum[n];
	    sum[0]=a[0];
	    int maxi=a[0];
	    
	    for(int i=1;i<n;i++)
	    {
	        sum[i]=a[i];
	        for(int j=0;j<i;j++)
	        {
	            if(a[j]<a[i])
	            {
	                sum[i] = max(sum[i],sum[j]+a[i]);
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        if(maxi<sum[i])
	        maxi=sum[i];
	    }
	 return maxi;   
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
