class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        vector<int>res;
        res.push_back(-1);
        
        
        int answer = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                res.push_back(i);
            }
            
            else{
                if(res.size()>1 && s[res.back()]=='(')
                {
                    res.pop_back();
                    
                    answer = max(answer,i-res.back());
                }
                
                else{
                    res.push_back(i);
                }
            }
            
            
        }
        
        return answer;
    }
};
