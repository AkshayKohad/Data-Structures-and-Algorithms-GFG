class Node{
    
    public:
    
    Node*next;
    Node*prev;
    int val;
    int key;
    Node(int val,int key)
    {
        next = NULL;
        prev = NULL;
         this->val = val; 
         this->key = key;
    }
};

class LRUCache
{
    private:

    public:
    
    Node*head;
    Node*tail;
    int capacity;
    
    unordered_map<int,Node*>mp;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        capacity = cap;
        
        head->next = tail;
        tail->prev = head;
        
        // code here
    }
    
    
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(mp.find(key)==mp.end())
        return -1;
        
        Node*temp = mp[key];
        
        Node*p = temp->prev;
        Node*n = temp->next;
        
        p->next = n;
        n->prev = p;
        
        Node*q = head->next;
        
        
        head->next = temp;
        temp->prev = head;
        temp->next = q;
        q->prev = temp;
        
        return mp[key]->val;
        
        // your code here
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if(mp.find(key)==mp.end())
        {
        
            Node*temp = new Node(value,key);
            
            if(mp.size()==capacity)
            {
                Node*t = tail->prev;
                
                Node*r = t->prev;
                
                mp.erase(t->key);
                
                r->next = tail;
                tail->prev = r;
                
                Node*q = head->next;
                
                head->next = temp;
                temp->prev = head;
                temp->next = q;
                q->prev = temp;
                
                mp[key] = temp;
                
            }
            
            else{
                Node*q = head->next;
                
                head->next = temp;
                temp->prev = head;
                temp->next = q;
                q->prev = temp;
                
                mp[key] = temp;
            }
            
        }
        
        
        else{
            Node*temp = mp[key];
            
            temp->val = value;
            
            Node*p = temp->prev;
            Node*n = temp->next;
            
            p->next = n;
            n->prev = p;
            
            Node*q = head->next;
            
            head->next = temp;
            temp->prev= head;
            temp->next = q;
            q->prev = temp;
        }
        // your code here   
    }
};
