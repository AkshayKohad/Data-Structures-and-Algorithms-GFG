//User function Template for C++

#define ll long long

class Solution{
public:
  void merge(int l,int mid,int r,vector<ll>&prefix_sum,ll &cnt_inversions){
      
      
      int i=l;
      int j=mid+1;
      
      vector<int>res_sorted;
      
      while(i<=mid && j<=r){
          if(prefix_sum[i]>prefix_sum[j]){
              cnt_inversions += mid-i+1;
              res_sorted.push_back(prefix_sum[j]);
              j++;
          }else{
              res_sorted.push_back(prefix_sum[i]);
              i++;
          }
      }
      
      while(i<=mid){
          res_sorted.push_back(prefix_sum[i]);
          i++;
      }
      while(j<=r){
          res_sorted.push_back(prefix_sum[j]);
          j++;
      }
      
      int w=0;
      for(int z=l;z<=r;z++){
          prefix_sum[z] = res_sorted[w];
          w++;
      }
  }
  void merge_sort(int l,int r,vector<ll>&prefix_sum,ll &cnt_inversions){
      if(l>=r)return;
      
      int mid = (r+l)/2;
      
      merge_sort(l,mid,prefix_sum,cnt_inversions);
      merge_sort(mid+1,r,prefix_sum,cnt_inversions);
      merge(l,mid,r,prefix_sum,cnt_inversions);
  }
  long long countSubstring(string S){
    // code here
    vector<ll>input;
    ll n = S.length();
    for (int i=0;i<n;i++){
        if(S[i]=='0'){
            input.push_back(-1);
        }else{
            input.push_back(1);
        }
    }
    
    ll result = 0;
    vector<ll>prefix_sum;
    ll pref = 0;
    
    for(int i=0;i<n;i++){
        pref+=input[i];
        prefix_sum.push_back(pref);
        
        if(pref>0){
            result++;
        }
    }
    
    reverse(prefix_sum.begin(),prefix_sum.end());
    
    ll cnt_inversions = 0;
    
    merge_sort(0,n-1,prefix_sum,cnt_inversions);
    
    return result+cnt_inversions;
  }
};
