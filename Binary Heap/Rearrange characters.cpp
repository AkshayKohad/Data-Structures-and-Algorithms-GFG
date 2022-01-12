#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 // } Driver Code Ends
class Solution
{
    public:
    
    struct mycmp{
      
      bool operator()(pair<char,int>f,pair<char,int>s)
      {
          return f.second<s.second;
      }
    };
    
    string rearrangeString(string str)
    {
        //code here
        priority_queue<pair<int,char>>pq;
        
        unordered_map<char,int>mp;
        int max =0;
        for(int i=0;i<str.length();i++)
        {
            mp[str[i]]++;
            if(mp[str[i]]>max)
            max=mp[str[i]];
        }
        
        if(max>str.length()-max+1)
        return "-1";
        
        for(auto x:mp)
        {
            pq.push(make_pair(x.second,x.first));
        }
        
        pair<int,char>prev = {-1,'#'};
        
        string a;
        while(a.length()!=str.length())
        {
            pair<int,char>curr = pq.top();
            pq.pop();
          // cout<<curr.second<<endl;
            if(curr.second == prev.second)
            {
             continue;   
            }
            
            else{
                
                a.push_back(curr.second);
                curr.first = curr.first-1;
                if(prev.second!='#')
                {
                    pq.push(prev);
                }
                prev=curr;
                
            }
        }
        
      //  cout<<a<<endl;
        return a;
    }
    
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}  // } Driver Code Ends
