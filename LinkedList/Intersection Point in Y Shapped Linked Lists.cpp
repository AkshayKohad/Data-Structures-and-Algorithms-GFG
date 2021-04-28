#include <iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    
    struct Node*p=head1;
    int count1=0;
    int count2=0;
    
    while(p!=NULL)
    {
        count1++;
        p=p->next;
    }
    p=head2;
    while(p!=NULL)
    {
        count2++;
        p=p->next;
    }
    struct Node*q;
    int k=abs(count1-count2);
    if(count1>=count2)
    {
        p=head1;
        q=head2;
        while(k--)
        {
            p=p->next;
        }
    }
    
    else{
        p=head2;
        q=head1;
        while(k--)
        {
            p=p->next;
        }
    }
    
    while(p!=NULL &&q!=NULL)
    {
        if(p==q)
        return p->data;
        
        p=p->next;
        q=q->next;
    }
    
    return -1;
    // Your Code Here
}

