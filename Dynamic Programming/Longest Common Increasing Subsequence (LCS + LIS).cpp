// User function template for C++

class Solution {
  public:
    int LCIS(const vector<int>& arr1, const vector<int>& arr2) {
        // code here
        
        int n = arr1.size();
        int m = arr2.size();
        
        int dp[m];
        
        for(int i=0;i<m;i++)
        dp[i]=0;
        
        for(int i=0;i<n;i++){
            int current=0;
            
            for(int j=0;j<m;j++){
                
                if(arr1[i]==arr2[j]){
                    dp[j] = max(dp[j],current+1);
                }
                else if(arr1[i]>arr2[j]){
                    current = max(dp[j],current);
                }
            
            
            }
        }
        
        int result = 0;
        
        for(int i=0;i<m;i++){
            result = max(result,dp[i]);
        }
        
        return result;
    }
};
