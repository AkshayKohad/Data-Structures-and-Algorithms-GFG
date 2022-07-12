struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    
    struct Node*p = a;
    struct Node*q = b;
    
    struct Node*head = (struct Node*)malloc(sizeof(struct Node));
   // head->next = NULL;
    struct Node*r = head;
    
    while(a!=NULL && b!=NULL)
    {
        if(a->data<b->data)
        {
            r->next = a;
            a=a->next;
            r=r->next;
        }
        
        else{
            r->next = b;
            b=b->next;
            r=r->next;
        }
    }
    
    if(a!=NULL)
    {
        r->next = a;
    }
    
    if(b!=NULL)
    {
        r->next = b;
    }
    
    return head->next;
}
