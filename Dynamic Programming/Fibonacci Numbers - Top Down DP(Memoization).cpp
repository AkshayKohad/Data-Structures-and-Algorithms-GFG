class Solution
{
    public:
    
    long long solution(int n,vector<long long>&res)
    {
        if(res[n]==-1)
        {
            long long val;
            
            if(n==0 || n==1)
            return n;
            
            else
            val = solution(n-1,res)+solution(n-2,res);
            
            res[n]=val;
        }
        
        return res[n];
    }
    //Function to find the nth fibonacci number using top-down approach.
    long long findNthFibonacci(int number)
    {
        // Your Code Here
        if(number==1 || number==0)
        return number;
        vector<long long>res(number+1,-1);
        solution(number,res);
        return res[number];
    }

};
