#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

static bool mycmp(vector<int>f,vector<int>s)
{
    if(f[0]==s[0])
    return f[1]<s[1];
    
    return f[0]<s[0];
}
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         
         sort(intervals.begin(),intervals.end(),mycmp);
         
         vector<vector<int>>res;
         
         res.push_back(intervals[0]);
         
        // cout<<intervals[0][0]<<" "<<intervals[0][1];
         int n = intervals.size();
         for(int i=1;i<n;i++)
         {
             int s = res.back()[0];
             int e = res.back()[1];
             
             int s1 = intervals[i][0];
             int e1 = intervals[i][1];
             
             if(e<s1)
             {
                 res.push_back(intervals[i]);
             }
             
             else{
                 
                 
                 res.pop_back();
                 if(e1>=e)
                 res.push_back({s,e1});
                 
                 else if(e1<e)
                res.push_back({s,e});
                 
             }
         }
         
         
         return res;
         
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends
