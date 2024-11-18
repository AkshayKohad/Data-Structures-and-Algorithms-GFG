class Solution {
  public:
    int countZeroes(vector<int> &arr) {
        // code here
        int n = arr.size();
        int l=0;
        int ans = n;
        int r=n-1;
        
        while(l<=r){
            int mid = (l+r)/2;
            
            if(arr[mid]==0){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return n-ans;
    }
};
