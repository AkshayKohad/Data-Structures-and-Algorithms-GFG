class Solution {
  public:
    int areMirror(Node* a, Node* b) {
        // Your code here
        queue<Node*>q_a;
        queue<Node*>q_b;
        
        q_a.push(a);
        q_b.push(b);
        
        while(!q_a.empty() && !q_b.empty()){
            int sz_a = q_a.size();
            int sz_b = q_b.size();
            
            if(sz_a != sz_b)return 0;
            vector<int>a_val;
            for(int i=0;i<sz_a;i++){
                Node*cur = q_a.front();
                q_a.pop();
                
                a_val.push_back(cur->data);
                
                if(cur->left!=NULL){
                    q_a.push(cur->left);
                }
                if(cur->right!=NULL){
                    q_a.push(cur->right);
                }
            }
            
            vector<int>b_val;
            for(int i=0;i<sz_b;i++){
                Node*cur = q_b.front();
                q_b.pop();
                
                b_val.push_back(cur->data);
                
                if(cur->left!=NULL){
                    q_b.push(cur->left);
                }
                if(cur->right!=NULL){
                    q_b.push(cur->right);
                }
            }
            
            int i=a_val.size()-1;
            int j=0;
            
            while(i>=0){
                if(a_val[i]!=b_val[j])return 0;
                i--;
                j++;
            }
            
        }
        
        return 1;
    }
};
