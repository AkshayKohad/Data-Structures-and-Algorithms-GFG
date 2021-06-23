class Solution 
{
    public:

    void solution(vector<int>&c,int B,int sum,vector<vector<int>>&a,vector<int>&b,int index)
    {
        if(sum==B)
        {
            if(b.size()!=0)
            a.push_back(b);
            
            return;
        }
        
        if(sum>B)
        {
            return;
        }
        for(int i=index;i<c.size();i++)
        {
            b.push_back(c[i]);
            solution(c,B,sum+c[i],a,b,i);
            b.pop_back();
        }
    }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>>a;
        unordered_set<int>s;
        for(int i=0;i<A.size();i++)
        s.insert(A[i]);
        vector<int>c;
        for(auto u:s)
        c.push_back(u);
        sort(c.begin(),c.end());
        vector<int>b;
        solution(c,B,0,a,b,0);
       
        return a;
    }
};
