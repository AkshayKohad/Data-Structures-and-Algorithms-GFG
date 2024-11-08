class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        
        int i=0;
        while(i<n && arr[i]==0)i++;
        
        string first;
        string second;
        
        while(i<n){
            if(i<n)first.push_back(arr[i]+'0');
            i++;
            
            if(i<n)second.push_back(arr[i]+'0');
            i++;
        }
        
        
        reverse(first.begin(),first.end());
        reverse(second.begin(),second.end());
        
        if(first.length()>second.length())second.push_back('0');
        
        string res;
        int carry = 0;
        int m = first.length();
        
        i=0;
        while(i<m){
            int val_first = first[i]-'0';
            int val_second = second[i]-'0';
            
            int result = val_first+val_second+carry;
            int divi = result%10;
            carry = result/10;
            
            res.push_back(divi+'0');
            i++;
        }
        
        if(carry>0)res.push_back(carry+'0');
        
        int j=res.length()-1;
        
        while(j>=0 && res[j]==0){
            res.pop_back();
            j--;
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};
