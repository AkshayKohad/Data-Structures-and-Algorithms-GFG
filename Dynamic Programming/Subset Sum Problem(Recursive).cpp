class Solution
{
    public:
    
    bool solution(int a[],int n,int sum,int res)
    {
        if(sum==res)
        return true;
        
        if(n==0)
        return false;
        
        return solution(a,n-1,sum-a[n-1],res+a[n-1]) || solution(a,n-1,sum,res);
    }
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    bool findPartition(int a[], int n)
    {
        // code here
        int sum = 0;
        int res = 0;
        for(int i=0;i<n;i++)
        sum = sum + a[i];
        
        return solution(a,n,sum,res);
    }
};
