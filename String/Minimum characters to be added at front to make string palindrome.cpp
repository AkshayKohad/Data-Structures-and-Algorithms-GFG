
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

void fill_lps(vector<int>&lps,string res)
{
    int len = 0;
    int i = 1;
    lps[0] = 0;
    int n = res.length();
    
    while(i<n)
    {
        if(res[i]==res[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        
        else{
            if(len==0)
            {
                lps[i] = 0;
                i++;
            }
            
            else{
                len = lps[len-1];
            }
        }
    }
}
    int minChar(string str){
        //Write your code here
        
        string str1 = str;
        string str2 = str;
        reverse(str2.begin(),str2.end());
        
        string res = str1 + "$" + str2;
        
        int n = res.length();
        
        vector<int>lps(n);
        
        fill_lps(lps,res);
        
        int m = str.length();
        
        
        return m-lps[n-1];
    }
};

