class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
         vector<int>a;
        if(root==NULL)
        return a;
        //Your code here
        queue<pair<int,Node*>>q;
        pair<int,Node*>p;
        p.first=0;
        p.second=root;

        q.push(p);

        map<int,vector<int>>m;

        while(q.empty()==false)
        {
            Node*curr = q.front().second;
            int level = q.front().first;
            q.pop();
           
            
                m[level].push_back(curr->data);
            

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
            a.insert(a.end(),(*it).second.begin(),(*it).second.end());
        }
     return a;   
    }
};

