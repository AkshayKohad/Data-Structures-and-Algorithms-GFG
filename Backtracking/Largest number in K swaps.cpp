class Solution
{
    public:
    
    
    bool check(char a,char b)
    {
        if(a>=b)return false;
        
        return true;
    }
    
    void solve(int i,string str,int k,string &res)
    {
        res = max(res,str);
        
        if(k==0 || i>=str.length())
        {
            return;
        }
        
        
        for(int j=i;j<str.length();j++)
        {
            if(i==j)
            {
               solve(i+1,str,k,res);    
            }
            
            else{
                if(check(str[i],str[j]))
                {
                swap(str[i],str[j]);
                
                solve(i+1,str,k-1,res);
                
                swap(str[i],str[j]);
                }
            }
            
            
        }
        
        
        
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       
       string res = str;
       solve(0,str,k,res);
       
       return res;
       
    }
};


