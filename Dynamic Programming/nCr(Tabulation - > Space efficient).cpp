class Solution
{
    public:
    const int p = 1e9+7;
    
    //Function to return nCr mod 10^9+7 for given n and r.
    int nCrModp(int n, int r) 
    {
        //array C[] is going to store last row of pascal triangle at the end.
        //last entry of last row is nCr. 
        int C[r+1];
        memset(C, 0, sizeof(C));
        
        //top row of Pascal Triangle 
        C[0] = 1; 
        
        //one by one constructing remaining rows of Pascal 
        //triangle from top to bottom.
        for (int i = 1; i <= n; i++) 
        { 
        //filling entries of current row using previous row values.
        for (int j = min(i, r); j > 0; j--)
          // nCj = (n-1)Cj + (n-1)C(j-1); 
          C[j] = (C[j]%p + C[j-1]%p)%p; 
        } 
        
        //returning the result.
        return C[r]; 
    }
};
