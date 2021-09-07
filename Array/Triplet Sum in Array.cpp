

 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int a[], int n, int X)
    {
        //Your Code Here
         sort(a,a+n);
   
    //Your Code Here
   for(int i=0;i<n;i++)
   {
       
      
       int sum = X-a[i];
       
       int j=i+1;
       int k=n-1;
       while(j<k)
       {
          
           
           if(a[j]+a[k]==sum)
           return true;
           
           else if(a[j]+a[k]<sum)
           j++;
           
           else if(a[j]+a[k]>sum)
           k--;
       }
       
   }
   
   return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends
