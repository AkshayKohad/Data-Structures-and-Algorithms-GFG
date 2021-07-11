#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends





// Function to calculate span
// price[]: price array in input
// n: size of array
vector <int> calculateSpan(int p[], int n)
{
   // Your code here
   vector<int>a;
   a.push_back(1);
   for(int i=1;i<n;i++)
   {
       if(p[i]<p[i-1])
       a.push_back(1);
       
       else{
           int f=a.size()-1;
           int count=0;
           while(f>=0 && p[f]<=p[i])
           {
               count=count+a[f];
               f=f-a[f];
           }
           a.push_back(count+1);
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		vector <int> s = calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
