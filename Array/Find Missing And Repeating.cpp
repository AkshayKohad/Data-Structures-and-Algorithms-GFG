#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int xor1 = 0;
        int xor2 = 0;
        
        for(int i=0;i<n;i++)
        {
            xor1 ^= arr[i];
        }
        
        for(int i=1;i<=n;i++)
        {
            xor2 ^= i;
        }
        
        int xor3 = xor1 ^ xor2;
        
        int val = xor3;
        int count = 0;
        while(val!=0)
        {
            if((val>>count)&1==1)
            {
                break;
            }
            count++;
        }
        
        int x = 0;
        int y = 0;
        
        for(int i=0;i<n;i++)
        {
            if((arr[i]>>count)&1 == 1)
            {
                x^=arr[i];
            }
            
            else{
                y^=arr[i];
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            if((i>>count)&1 == 1)
            {
                x^=i;
            }
            
            else{
                y^=i;
            }
        }
        
        int A,B;
        for(int i=0;i<n;i++)
        {
            if(x == arr[i])
            {
                B = x;
                A = y;
                break;
            }
            
            else if(y == arr[i])
            {
                B = y;
                A = x;
                break;
            }
        }
        
        int* res = new int[2];
        
        res[0] = B;
        res[1] = A;
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
