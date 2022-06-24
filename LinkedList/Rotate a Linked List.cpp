struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        
        int count = 0;
        
        Node*p = head;
        Node*r = NULL;
        while(p!=NULL)
        {
            count++;
            r = p;
            p=p->next;
        }
        
        
        
        k = k%count;
        
        if(k==0)
        return head;
        
        r->next = head;
        
        Node*fast = head;
        Node*slow = NULL;
        
        //int c = count-k;
        
        while(k--)
        {
            slow = fast;
            fast = fast->next;
            
        }
        
        slow->next = NULL;
        head = fast;
        
        
        return head;
        // Your code here
    }
};
