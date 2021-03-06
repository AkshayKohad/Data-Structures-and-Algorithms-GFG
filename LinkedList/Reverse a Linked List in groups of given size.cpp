#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct node *reverse (struct node *head, int k);

struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        head = reverse(head, k);
        printList(head);
    }
     
    return(0);
}

// } Driver Code Ends


/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
    struct node*t=head;
    struct node*u;
    struct node*p=head;
    int f=k;
    struct node*q=NULL;
    struct node*r=NULL;
    
    while(p!=NULL && f--)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
    while(p!=NULL)
    {
        q=NULL;
        r=NULL;
        u=p;
        f=k;
       while(p!=NULL && f--)
      {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
       }
       t->next=q;
       t=u;
        
    }
    return head;
}
