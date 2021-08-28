#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    int forward[n];
	    int backward[n];
	    
	    forward[0]=1;
	    
	    for(int i=1;i<n;i++)
	    {
	        forward[i]=1;
	        for(int j=0;j<i;j++)
	        {
	            if(nums[i]>nums[j])
	            {
	                forward[i] = max(forward[i],forward[j]+1);
	            }
	        }
	    }
	    
	    backward[n-1]=1;
	    for(int i=n-2;i>=0;i--)
	    {
	        backward[i]=1;
	        for(int j=n-1;j>i;j--)
	        {
	            if(nums[i]>nums[j])
	            {
	                backward[i] = max(backward[i],backward[j]+1);
	            }
	        }
	    }
	    
	    int res=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(res<backward[i]+forward[i]-1)
	        res = backward[i]+forward[i]-1;
	    }
	    
	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
