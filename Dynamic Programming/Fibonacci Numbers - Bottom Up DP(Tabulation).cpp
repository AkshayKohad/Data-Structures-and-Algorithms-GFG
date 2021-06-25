class Solution
{
    public:
    //Function to find the nth fibonacci number using bottom-up approach.
    long long findNthFibonacci(int number)
    {
        // Your Code Here
        if(number==0 || number==1)
        return number;
        
        vector<long long>res(number+1,-1);
        res[0]=0;
        res[1]=1;
        
        for(int i=2;i<=number;i++)
        {
            res[i]=res[i-1]+res[i-2];
        }
        
        return res[number];
    }
};
