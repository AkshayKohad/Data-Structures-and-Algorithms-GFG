class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        
        vector<int>a;
        for(int i=0;i<n;i++)
        {
            a.push_back(i+1);
            
        }
        
        int fact = 1;
        
        for(int i=1;i<n;i++)
        {
            fact *= i;
        }
        
        string res;
        
        k = k-1;
        
        while(true)
        {
            int index = k/fact;
            res += to_string(a[index]);
            
            a.erase(a.begin()+index);
            
            if(a.size()==0)
            break;
            
            k = k%fact;
            
            fact = fact/a.size();
        }
        
        return res;
        // code here
    }
};
