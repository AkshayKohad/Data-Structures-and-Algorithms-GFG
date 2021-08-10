//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
	bool recreationalSpot(int arr[], int n){
		// Your code goes here 
		
	stack<int>s;
		
		int min[n];
		
		
		min[0]=arr[0];
	
		for(int i=1;i<n;i++)
		{
		    if(min[i-1]<arr[i])
		    min[i]=min[i-1];
		    
		    else{
		        min[i]=arr[i];
		    }
		}
	
	for(int j=n-1;j>=0;j--)
	{
	    if(arr[j]>min[j])
	    {
	        while(s.empty()==false && min[j]>=s.top())
	        {
	            s.pop();
	        }
	        
	        if(s.empty()==false && s.top()<arr[j])
	        return true;
	        
	        s.push(arr[j]);
	    }
	}
	    
	   
	return false;	
	}
	
	
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution ob;
		if(ob.recreationalSpot(arr, n))
		    cout<<"True"<<endl;
		else
		    cout<<"False"<<endl;
	}
	return 0;
}  // } Driver Code Ends
