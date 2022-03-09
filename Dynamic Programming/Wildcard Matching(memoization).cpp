#include<bits/stdc++.h>
using namespace std;

bool solve(string &a,string &b,int n,int m,vector<vector<int>>&memo)
{
	if(n==0 && m==0)
	return 1;

   if(m==0)
	{
		return 0;
	}


 if(memo[n][m]!=-1)
  return memo[n][m];

	if(n==0)
	{
		if(m!=0)
		{
         if(b[m-1]=='*')
		 return memo[n][m] = solve(a,b,n,m-1,memo);

		 else
		 return memo[n][m] = 0;
		}
		
		return 0;
	}

	
 

	if(a[n-1]==b[m-1])
	{
		return memo[n][m] = solve(a,b,n-1,m-1,memo);
	}

	else{
		if(b[m-1]=='?')
		{
			return memo[n][m] = solve(a,b,n-1,m-1,memo);
		}

		else if(b[m-1]=='*')
		{
			return memo[n][m] = solve(a,b,n-1,m-1,memo) || solve(a,b,n-1,m,memo)||solve(a,b,n,m-1,memo);
		}

		else
		return memo[n][m]=0;
	}

	

}
int main() {
	string a,b;

	cin>>a;
	cin>>b;
    int n = a.length();
	int m = b.length();
	vector<vector<int>>memo(n+1,vector<int>(m+1,-1));
	if(solve(a,b,n,m,memo)==1)
	cout<<"MATCHED";

	else
	cout<<"NOT MATCHED";
	return 0;
}
