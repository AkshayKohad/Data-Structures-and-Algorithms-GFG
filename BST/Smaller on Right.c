#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
 struct Node *left;
 struct Node *right;
};


int countNodes(struct Node*root)
{
    if(root==NULL)
    return 0;

    return countNodes(root->left)+countNodes(root->right)+1;
}
struct Node *searchNode(struct Node*root,int x,int *res)
{
    if(root==NULL)
    return NULL;
    
    struct Node*k;
    if(root->data>x)
   k=searchNode(root->left,x,res);
    
    else if(root->data<x)
    {
        *res=*res + countNodes(root->left);
        *res=*res+1;
    k=searchNode(root->right,x,res);
    }
    
    else if(root->data==x)
    return root;
    
    return k;
    
}
// struct Node *searchAndCreateNode(struct Node*root,int x, int f)
// {
//     if(root->data>f)
//     root->left = searchAndCreateNode(root->left,x,f);
    
//     else if(root->data<f)
//     root->right = searchAndCreateNode(root->right,x,f);
    
//     else
//     {
//         struct Node*p = (struct Node*)malloc(sizeof(struct Node));
//         p->data = x;
//         p->left=NULL;
//         p->right=NULL;
        
//         if(x>=f)
//         {
//             struct Node*q=root;
//             while(q->right!=NULL)
//             {
//                 q=q->right;
//             }
           
//             q->right=p;
            
           
//         }
        
        
//         else{
//         struct Node*q=root;
        
//          while(q->left!=NULL)
//             {
//                 q=q->left;
//             }
//             q->left=p;
//         }
//     }
    
//     return root;
// }


struct Node *createNode(struct Node*root,int x)
{
    if(root==NULL)
    {
       struct Node*t = (struct Node*)malloc(sizeof( struct Node));
        t->data = x;
        t->left=NULL;
        t->right=NULL;
       
        return t;
    }
     else if(root->data==x)
     {
          struct Node*t = (struct Node*)malloc(sizeof( struct Node));
        t->data = x;
        t->left=NULL;
        t->right=NULL;
      t->left=root->left;
      root->left=t;
     }
    
    
    else if(root->data>x)
    {
        root->left = createNode(root->left,x);
    }
    
    else if(root->data<x)
    {
        root->right = createNode(root->right,x);
    }
    
    return root;
}
int main() {
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n];
        
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        
        struct Node* root=NULL;
         int max=-1;
     
        for(int i=n-1;i>=0;i--)
        {
            int res=0;
            
      
           
           
               root = createNode(root,a[i]);
               searchNode(root,a[i],&res);
             
           if(res>max)
           max=res;
        }
      
        
       
        
        
        
        
        
        printf("%d\n",max);
        
    }
	//code
	return 0;
}
