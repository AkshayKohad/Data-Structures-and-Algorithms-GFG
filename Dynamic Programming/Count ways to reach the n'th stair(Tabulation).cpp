class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        //we use same algorithm as Fibonacci series to find the
        //number of ways to reach the nth stair.
        
        
        int mod = 1000000007;
        //base case
        if (n <= 1) 
        return 1;
        
        //initializing base values for Fibonacci series.
        int a = 1, b = 1, temp;
        
        for (int i = 2; i <= n; i++)
        {
            temp = (a + b) % mod;
            
            //updating a as b and b as temp(sum of a and b).
            a = b;
            b = temp;
        }
        
        //returning the result.
        return b;
    }
};
