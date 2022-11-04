
class Solution{   
  public:
  
     bool isPalindrome(string &s)
    {
        int l=0,r=s.size()-1;
        while(l<r)  if(s[l++]!=s[r--])  return false;
        return true;
    }
    
    
    // Function to check if a palindrome pair exists
    bool palindromepair(int n, string words[]) {
        // code here
        vector<vector<int>>res;
        unordered_map<string,int>mp;
        
        for(int i=0;i<n;i++)
        {
            string s = words[i];
            
            reverse(s.begin(),s.end());
            
            mp[s] = i;
        }
        
        
        //Blank
        if(mp.count(""))
        {
            int blankidx = mp[""];
            for(int i=0;i<n;i++)
            {
                if(blankidx!=i && isPalindrome(words[i]))
                {
                    
                    return true;
                }
            }
        }
        
        //Reflective
        for(int i=0;i<n;i++)
        {
           string cur = words[i];
            
            
            if(mp.count(cur) && mp[cur]!=i)
            {
              int idx = mp[cur];
                return true;
    
            }
            
        }
        
        
        
        for(int i=0;i<n;i++)
        {
            // track all prefix and suffix of tree
            
            for(int j=1;j<words[i].length();j++)
            {
                
               string prefix = words[i].substr(0,j);
                
               string suffix = words[i].substr(j);
                
               
                if(mp.count(suffix) && mp[suffix]!=i && isPalindrome(prefix))
                {
                        return true;
                       
                }
                
                if(mp.count(prefix) && mp[prefix]!=i && isPalindrome(suffix))
                {
                       return true;
                             
                }
            }
        }
        return false;
    }

};
