// dict : given set of strings
// pattern : given pattern

struct Node{
    bool isEndOfWord;
    map<char, Node *> mp;
};

Node *newNode(){
    Node *temp = new Node();
    temp->isEndOfWord = false;
    return temp;
}
class Solution
{
    public:
    
    static bool mycmp(string a,string b)
    {
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        int k;
        if(a.length()>b.length())
        k=b.length();
        
        else
        k=a.length();
        
        for(int i=0;i<k;i++)
        {
            if(a[i]!=b[i])
            return a[i]<b[i];
            
        }
        
        
        return a.length()<b.length();
        
    }
    
    Node* insert(Node*root,string s)
    {
        Node*curr = root;
         for(int i=0;i<s.length();i++)
         {
             if(curr->mp.find(s[i]) == curr->mp.end())
             curr->mp[s[i]] = newNode();
             
             curr = curr->mp[s[i]];
         }
         
         curr->isEndOfWord=true;
         
         return root;
    }
    
    
    bool searchPattern(Node*root,string key,string pattern)
    {
        Node*curr = root;
        int j=0;
        for(int i=0;i<key.length();i++)
        {
            if(j==pattern.length())
            return true;
            
            if(curr->mp.find(key[i])==curr->mp.end())
            return false;
            
            
            if(key[i]>=65 && key[i]<=90)
            {
                if(key[i]==pattern[j])
                j++;
                
                else
                return false;
                
            }
            
            curr = curr->mp[key[i]];
        }
        if(j==pattern.length())
        return true;
        
        return false;
    }
    
    //Function to print all words in the CamelCase dictionary 
    //that matches with a given pattern.
    void findAllWords(vector<string> dict, string pattern) 
    {
        //code here
       // vector<string>s;
       set<string>s;
       vector<string>res;
        Node *root = newNode();
        
        for(int i=0;i<dict.size();i++)
        {
               root = insert(root,dict[i]);
               
               if(searchPattern(root,dict[i],pattern)==true)
               {
                   s.insert(dict[i]);
                   res.push_back(dict[i]);
               }
    
        }
        
        sort(res.begin(),res.end(),mycmp);
        
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<" ";
        }
        
        if(s.size()==0)
        cout<<"No match found"<<endl;
       
    }
};
