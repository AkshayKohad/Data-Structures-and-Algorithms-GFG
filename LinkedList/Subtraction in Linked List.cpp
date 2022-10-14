bool Isgreater(Node*l1,Node*l2)
{
    Node*list1 = l1;
    Node*list2 = l2;
    
    int count1 = 0;
    int count2 = 0;
    
    while(list1!=NULL && list1->data==0)
    {
        list1 = list1->next;
    }
    
    while(list2!=NULL && list2->data==0)
    {
        list2 = list2->next;
    }
    
    Node*t1 = list1;
    Node*t2 = list2;
    
     while(list1!=NULL)
    {
        list1 = list1->next;
        count1++;
    }
    
    while(list2!=NULL)
    {
        list2 = list2->next;
        count2++;
    }
    
    
    if(count1>count2)
    return true;
    
    else if(count1<count2)
    return false;
    
    
    while(t1!=NULL && t2!=NULL)
    {
        if(t1->data>t2->data)
        return true;
        
         if(t1->data<t2->data)
        return false;
        
        t1 = t1->next;
        t2 = t2->next;
    }
    
    return true;
}

Node* subLinkedList(Node* l1, Node* l2)
{
    //Your code here
    
//    reverse(l1);
    
  //  reverse(l2);
    
    if(!Isgreater(l1,l2))
    {
        return subLinkedList(l2, l1);  
    }
    
    Node*r = NULL;
    Node*p = NULL;
    Node*q = l1;
    
    
    while(q!=NULL)
    {
        r  = p;
        p = q;
        q = q->next;
        p->next = r;
    }
    
    
    
    
    l1 = p;
    
    r = NULL;
    p = NULL;
    q = l2;
    
    
    while(q!=NULL)
    {
        r  = p;
        p = q;
        q = q->next;
        p->next = r;
    }
    
    
    
    
    l2 = p;
    
    
    
    
    
    Node*list1 = l1;
    Node*list2 = l2;
    
    
    Node*head = new Node(-1);
    Node*w = head;
    
    bool burrow = false;
    while(list1!=NULL && list2!=NULL)
    {
        
        int x = list1->data;
            int y = list2->data;
        if(list1->data >= list2->data)
        {
            
            if(burrow)
            {
                x--;
                
                if(x>=y)
                {
                    burrow = false;
                    
                    Node*n = new Node(x-y);
                    
                    w->next = n;
                    w = n;
                }
                
                else{
                    burrow = true;
                    
                    x = x+10;
                    
                     Node*n = new Node(x-y);
                    
                    w->next = n;
                    w = n;
                }
            }
            
            
            else{
                burrow = false;
                    
                    Node*n = new Node(x-y);
                    
                    w->next = n;
                    w = n;
            }
        }
        
        else{
            if(burrow)
            {
                burrow = true;
                
                x = x+10;
                x--;
                
                Node*n = new Node(x-y);
                    
                    w->next = n;
                    w = n;
                
            }
            
            else{
                burrow = true;
                
                x = x+10;
            
                
                Node*n = new Node(x-y);
                    
                    w->next = n;
                    w = n;
            }
        }
        
        list1 = list1->next;
        
        list2 = list2->next;
    }
    
    while(list1!=NULL)
    {
        int x = list1->data;
        
        if(burrow)
        {
            if(x==0)
            {
                burrow = true;
                
                x = x+10;
                x--;
                
                 Node*n = new Node(x);
                    
                    w->next = n;
                    w = n;
            }
            
            else{
                burrow = false;
                
               
                x--;
                
                 Node*n = new Node(x);
                    
                    w->next = n;
                    w = n;
            }
        }
        
        else{
            burrow = false;
             Node*n = new Node(x);
                    
                    w->next = n;
                    w = n;
        }
        
        
        list1 = list1->next;
    }
    
    
    
    while(list2!=NULL)
    {
        int x = list2->data;
        
        if(burrow)
        {
            if(x==0)
            {
                burrow = true;
                
                x = x+10;
                x--;
                
                 Node*n = new Node(x);
                    
                    w->next = n;
                    w = n;
            }
            
            else{
                burrow = false;
                
               
                x--;
                
                 Node*n = new Node(x);
                    
                    w->next = n;
                    w = n;
            }
        }
        
        else{
            burrow = false;
             Node*n = new Node(x);
                    
                    w->next = n;
                    w = n;
        }
        
        
        list2 = list2->next;
    }
    
    r = NULL;
    p = NULL;
    q = head->next;
    
    
    while(q!=NULL)
    {
        r  = p;
        p = q;
        q = q->next;
        p->next = r;
    }
    
    Node*res = p;
    
    while(res!=NULL)
    {
        if(res->data==0)
        {
            Node*t = res;
            res = res->next;
            
            delete t;
        }
        
        else{
            break;
        }
    }
    
    if(res==NULL)
    {
        Node*n = new Node(0);
        return n;
    }
    
    return res;
}
