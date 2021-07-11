#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends





// Function to store Next larger elements


vector <long long> nextLargerElement(long long arr[], int n){
    // Your code here
    stack<long long>st;
    vector<long long>a(n);
    
    a[n-1]=-1;
    st.push(arr[n-1]);
    
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<st.top())
        {
            a[i]=st.top();
            st.push(arr[i]);
        }
        
        else{
            long long f=-1;
            while(st.size()!=0)
            {
                if(arr[i]<st.top())
                {
                    f=st.top();
                   // st.push(arr[i]);
                    break;
                }
                st.pop();
                
            }
            a[i]=f;
            st.push(arr[i]);
        }
        
    }
    
    return a;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        vector <long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
  // } Driver Code Ends
