class Solution
{
    public:
    
    int solution(int w,int wt[],int val[],int n,int count)
    {
        if(n==0)
        return count;
        
        if(w<wt[n-1])
        return solution(w,wt,val,n-1,count);
        
        else{
            return max(solution(w-wt[n-1],wt,val,n-1,count+val[n-1]),solution(w,wt,val,n-1,count));
        }
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
      int count = 0;
      
      return solution(w,wt,val,n,count);
      
    }
};
