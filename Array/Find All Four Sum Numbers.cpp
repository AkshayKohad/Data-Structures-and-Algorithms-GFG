class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &a, int k) {
        // Your code goes here
        vector<vector<int>>res;
        int n = a.size();
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            int k1 = k-a[i];
            
            for(int j=i+1;j<n;j++)
            {
                int k2 = k1-a[j];
                
                int s = j+1;
                int e = n-1;
                while(s<e)
                {
                    if(a[s]+a[e]==k2)
                    {
                        res.push_back({a[i],a[j],a[s],a[e]});
                        int val1 = a[s];
                        int val2 = a[e];
                        
                        while(s<e && val1==a[s])
                        s++;
                        
                        while(s<e && val2==a[e])
                        e--;
                    }
                    
                    
                    else if(a[s]+a[e]>k2)
                    e--;
                    
                    else
                    s++;
                }
                
                while(j+1<n && a[j]==a[j+1])
                j++;
            }
            
            while(i+1<n && a[i]==a[i+1])
            i++;
            
        }
        
        return res;
    }
};
