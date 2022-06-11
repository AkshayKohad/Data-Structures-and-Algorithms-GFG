#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int a[], int n, int m) {
        // code here
        
        int res = 0;
        int j=0;
        int i=0;
        int zero = 0;
        while(j<n)
        {
            if(a[j]==1)
            {
                res = max(j-i+1,res);
                j++;
                
                
            }
            
            else{
                if(zero<m)
                {
                zero++;
                 res = max(j-i+1,res);
                j++;
                
               
                }
                
                else{
                    if(a[i]==0)
                    {
                        zero--;
                        i++;
                    }
                    
                    else{
                        i++;
                    }
                    
                }
                
            }
            
        }
        
        return res;
    }  
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
