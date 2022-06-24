class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        
        int i=0;
        while(i<str.length() && str[i]==' ')
        i++;
        
        bool is_neg = false;
        
        if(i<str.length() && str[i]=='-')
        {
            is_neg = true;
            i++;
        }
        
        else if(i<str.length() && str[i]=='+')
        {
            i++;
        }
        
        int res = 0;
        
        //-1985048454
        //1985048454
        
        while(i<str.length())
        {
            if(!isdigit(str[i]))
            return -1;
            
            int val = str[i] - '0';
            
            if(res>(INT_MAX-val)/10)
            {
                  if(is_neg)
                    return INT_MIN;
                else
                return INT_MAX;
            }
            
            res = res*10 + val;
            i++;
        }
        
        if(res==0)
        return 0;
        
        if(is_neg)
        return -res;
        
        return res;
    }
};
