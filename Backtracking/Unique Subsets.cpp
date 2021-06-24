class Solution
{
    public:
    
    bool isSafe(vector<int>&b,vector<vector<int>>&a,int x)
    {
        b.push_back(x);
        for(int i=0;i<a.size();i++)
        {
            if(b==a[i])
            {
                b.pop_back();
                return false;
            }
        }
        
        b.pop_back();
        return true;
    }
    void solution(vector<int>arr,int n,vector<vector<int>>&a,vector<int>&b,int l)
    {
        a.push_back(b);
        if(l>=n)
        return;
        
        
        
        for(int i=l;i<n;i++)
        {
            if(isSafe(b,a,arr[i]))
            {
            b.push_back(arr[i]);
            solution(arr,n,a,b,i+1);
            b.pop_back();
            }
        }
    }
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        sort(arr.begin(),arr.end());
        vector<vector<int>>a;
        vector<int>b;
       // a.push_back(b);
        solution(arr,n,a,b,0);
        return a;
    }
};
