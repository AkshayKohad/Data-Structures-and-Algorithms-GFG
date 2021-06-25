class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        // Code here 
        vector<int>police;
        vector<int>thief;
        for(int i=0;i<n;i++)
        {
            if(arr[i]=='P')
            police.push_back(i);
            
            else{
                thief.push_back(i);
            }
        }
        //int index=0;
        int i=0;
        int j=0;
        int count=0;
        while(i<police.size() && j<thief.size())
        {
            if(police[i]>thief[j])
            {
                if(police[i]-k<=thief[j])
                {
                    count++;
                    j++;
                    i++;
                }
                
                else{
                    j++;
                }
            }
            
            else{
                if(police[i]+k>=thief[j])
                {
                    count++;
                    j++;
                    i++;
                }
                
                else{
                    i++;
                }
            }
        }
        
            
            
        return count;
    }
};
