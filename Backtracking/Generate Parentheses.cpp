//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    
void solution(string a,int count,int count1,int n,vector<string>&b)
{
    if(count==n)
	{
         while(count1!=n)
		 {
			 a.push_back(')');
			 count1++;
		 }

		 b.push_back(a);
		 return;
	}

	if(count==count1)
	{
		a.push_back('(');
		solution(a,count+1,count1,n,b);
		a.pop_back();
	}
	else if(count>count1){

	  a.push_back('(');
		solution(a,count+1,count1,n,b);
		a.pop_back();

		a.push_back(')');
		solution(a,count,count1+1,n,b);
		a.pop_back();
	}
}

static bool mycmp(string &a,string &b)
{
	return a>b;
}


    vector<string> AllParenthesis(int n) 
    {
        
        

	int count=0;
	int count1=0;
   string a;
   vector<string>b;
   solution(a,count,count1,n,b);

   sort(b.begin(),b.end(),mycmp);
   return b;
        // Your code goes here 
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends
