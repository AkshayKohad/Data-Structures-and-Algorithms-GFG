
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution
{
    public:
    priority_queue<int>l;
    priority_queue<int,vector<int>,greater<int>>s;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(l.size()==0 && s.size()==0)
        {
            l.push(x);
            
        }
        
       else if(l.size()>s.size())
        {
            if(l.top()<=x)
            {
                s.push(x);
            }
            
            else{
                int k = l.top();
                l.pop();
                l.push(x);
                s.push(k);
            }
            
        }
        
        else if(l.size()==s.size())
        {
            if(s.top()>=x)
            {
                l.push(x);
            }
            
            else
            {
                 int k = s.top();
                s.pop();
                s.push(x);
                l.push(k);
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if((l.size()+s.size())%2==0)
        return (l.top() + s.top())/2;
        
        else
        return l.top();
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends
