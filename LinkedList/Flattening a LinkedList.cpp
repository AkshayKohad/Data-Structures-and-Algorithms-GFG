#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
void intialize(Node*curr)
{
    while(curr!=NULL)
    {
        Node*temp = curr;
        curr->next = curr->bottom;
        curr = curr->bottom;
        temp->bottom = NULL;
        
        
    }
}
   
   
   
Node* merge(Node*p,Node*q)
{
    Node*head = NULL;
    Node*present =NULL;
    if(p->data<q->data)
    {
       // cout<<p->data<<endl;
        head = p;
        present = head;
        p=p->next;
    }
    
    else{
       // cout<<q->data<<endl;
        head = q;
        present = head;
        q = q->bottom;
        head->next = NULL;
    }
    
    while(p!=NULL && q!=NULL)
    {
        if(p->data<q->data)
        {
           // cout<<p->data<<endl;
            present->next = p;
            present = p;
            p = p->next;
            present->next = NULL;
        }
        
        else{
          //  cout<<q->data<<endl;
         present->next = q;
         present = q;
         q = q->bottom;
         present->next = NULL;
        }
    }
    
    
    if(p!=NULL)
    {
      present->next = p;  
    }
    
    while(q!=NULL)
    {
        present->next = q;
        present = q;
        q = q->bottom;
        present->next = NULL;
    }
    
    return head;
}
Node *flatten(Node *root)
{
    
    if(root==NULL)
    return root;
    
    
    Node*curr_next = root->next;
    Node*curr = root;
    intialize(curr);
    
    
   // while(root!)
    while(curr_next!=NULL)
    {
        curr = root;
       Node* curr_next_next = curr_next->next;
       root =  merge(curr,curr_next);
        curr_next = curr_next_next;
    }
    
    Node*t = root;
    // while(t!=NULL)
    // {
    //     cout<<t->data<<" ";
    //     t=t->next;
    // }
    Node*t1 = root;
    while(t!=NULL)
    {
        t1->bottom = t->next;
        t1 = t1->bottom;
        t = t->next;
    }
   // cout<<endl;
    return root;
   // Your code here
}

