#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int nums[], int n){
	    //code
	     if(n==1)
            return nums[0];
        
        int l = 0;
        int h = n-1;
        
        while(l<h)
        {
         int mid = (l+h)/2;
            
            if(mid!=0 && mid!=n-1)
            {
                if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                    return nums[mid];
                
                else if(nums[mid]==nums[mid+1])
                {
                    if((mid+1+1)%2==0)
                    {
                        l = mid+1;
                    }
                    
                    else{
                        h = mid-1;
                    }
                }
                
                else if(nums[mid]==nums[mid-1])
                {
                   if((mid+1)%2==0)
                   {
                       l = mid+1;
                   }
                    
                    else{
                        h = mid-1;
                    }
                }
            }
            
            else if(mid==0)
            {
                if(nums[mid]!=nums[mid+1])
                    return nums[mid];
                
                else
                    l = mid+1;
                
            }
            
            else if(mid==n-1)
            {
                if(nums[mid]!=nums[mid-1])
                    return nums[mid];
                
                else
                    h = mid-1;
            }
            
        }
        
        return nums[l];
    
	}
};
