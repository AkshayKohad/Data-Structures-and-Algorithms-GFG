class Solution {
  public:
    vector<int> printUnsorted(vector<int>& arr) {
        // Code here
        int n = arr.size();
        int s=0;
        for(s=0;s<n-1;s++){
            if(arr[s]>arr[s+1])break;
        }
        
        if(s==n-1)return {0,0};
        
        int e=n-1;
        
        for(e=n-1;e>=1;e--){
            if(arr[e]<arr[e-1])break;
        }
        
        int maxi = arr[s];
        int mini = arr[s];
        
        for(int i=s;i<=e;i++){
            maxi = max(arr[i],maxi);
            mini = min(arr[i],mini);
        }
        
        int ind_start = s;
        for(int i=0;i<s;i++){
            if(mini<arr[i]){
                ind_start = i;
                break;
            }
        }
        
        int ind_end = e;
        for(int j=n-1;j>e;j--){
            if(maxi>arr[j]){
                ind_end = j;
                break;
            }
        }
        
        return {ind_start,ind_end};
    }
};
