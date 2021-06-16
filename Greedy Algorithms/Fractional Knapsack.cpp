#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};



class Solution
{
    public:
   static bool mycmp(Item i1, Item i2)
    {
        double r1 = (double)i1.value/i1.weight;
        double r2 = (double)i2.value/i2.weight;
        
        return r1>r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        sort(arr,arr+n,mycmp);
        double res = 0.0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i].weight<=W)
            {
            res = res+arr[i].value;
            W=W-arr[i].weight;
            }
            
            else{
                res = res + ((double)W/arr[i].weight)*arr[i].value;
                break;
            }
        }
        return res;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
