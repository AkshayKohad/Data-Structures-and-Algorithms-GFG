class Solution
{
    public:
    int countKdivPairs(int a[], int n, int k)
    {
        //code here
        int count=0;
        // unordered_map<int,int>m;
       
        
        vector<int>v(k,0);
        
         for(int i=0;i<n;i++)
        {
            v[a[i]%k]++;
        }
        
        for(int i=0;i<v[0];i++)
        count=count+i;
        
        int j=1;
        int z=k-1;
        
        while(j<z)
        {
            count=count+v[j]*v[z];
            j++;
            z--;
        }
        
        if(j==z)
        {
            for(int i=0;i<v[j];i++)
            {
                count=count+i;
            }
        }
        
       
        return count;
    }
};
