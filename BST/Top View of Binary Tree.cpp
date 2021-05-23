class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>a;
        if(root==NULL)
        return a;
        //Your code here
        queue<pair<int,Node*>>q;
        pair<int,Node*>p;
        p.first=0;
        p.second=root;
        
        q.push(p);
        
        map<int,int>m;
        
        while(q.empty()==false)
        {
            Node*curr = q.front().second;
            int level = q.front().first;
            q.pop();
            if(m.find(level)==m.end())
            {
                m[level]=curr->data;
            }
            
            if(curr->left!=NULL)
            {
                pair<int,Node*>r;
                r.first = level-1;
                r.second = curr->left;
                q.push(r);
            }
            
            if(curr->right!=NULL)
            {
                pair<int,Node*>r;
                r.first = level+1;
                r.second = curr->right;
                q.push(r);
            }
        }
        
        for(auto it = m.begin();it!=m.end();it++)
        {
            a.push_back((*it).second);
        }
     return a;   
    }

};
