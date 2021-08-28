// Space complexity O(V*M)

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	
// 	int solution(int coins[],int m,int v)
// 	{
//       if(v<0)
//       return -1;
       
//       if(v==0)
//       return 0;
       
//       if(m==0)
//       return -1;
       
//       int res1 = solution(coins,m,v-coins[m-1]);
//       int res2 = solution(coins,m-1,v);
       
//       if(res1==-1 && res2==-1)
//       return -1;
       
//       else if(res1==-1)
//       return res2;
       
//       else if(res2==-1)
//       return res1+1;
       
       
//       return min(res1+1,res2);
       
       
// 	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	   // int res = solution(coins,M,V);
	    
	    int dp[M+1][V+1];
	    
	    for(int i=0;i<=M;i++)
	    dp[i][0]=0;
	    
	    for(int i=1;i<=V;i++)
	    dp[0][i]=-1;
	    
	    
	    for(int i=1;i<=M;i++)
	    {
	        int res1,res2;
	        for(int j=1;j<=V;j++)
	        {
	            
	            if(j-coins[i-1]<0)
	            res1 = -1;
	            
	            else
	            res1 = dp[i][j-coins[i-1]];
	            
	            res2 = dp[i-1][j];
	            
	            if(res1==-1 && res2==-1)
                 dp[i][j]=-1;
                 
                  else if(res1==-1)
                  dp[i][j] = res2;
       
                 else if(res2==-1)
                 dp[i][j] = res1+1;
	            
	            else
	            dp[i][j] = min(res1+1,res2);
	            
	        }
	    }
	    
	    return dp[M][V];
	    
	    
	} 
	  
};


// Space complexity O(V)

class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // table[i] will be storing the minimum number of coins 
	    // required for i value.  So table[V] will have result 
	    int table[V+1]; 
	  
	    // Base case (If given value V is 0) 
	    table[0] = 0; 
	  
	    // Initialize all table values as Infinite 
	    for (int i=1; i<=V; i++) 
	        table[i] = INT_MAX; 
	  
	    // Compute minimum coins required for all 
	    // values from 1 to V 
	    for (int i=1; i<=V; i++) 
	    { 
	        // Go through all coins smaller than i 
	        for (int j=0; j<M; j++) 
	        {
	          	if (coins[j] <= i) 
	          	{ 
	              	int sub_res = table[i-coins[j]]; 
	              	if(sub_res != INT_MAX && sub_res + 1 < table[i]) 
	                  	table[i] = sub_res + 1; 
	          	}
	        } 
	    } 

	    if(table[V]==INT_MAX)
	    	return -1;

	    return table[V]; 
	} 
	  
};






// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
