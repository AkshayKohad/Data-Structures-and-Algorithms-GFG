class Solution{   
public:

   
   class Binary_Trie{
     public:
     
     Binary_Trie*left;
     Binary_Trie*right;
     
     Binary_Trie()
     {
         left=NULL;
         right=NULL;
     }
       
   };
   
   
   void insert(Binary_Trie*head,int val)
   {
       Binary_Trie*p = head;
       
       for(int i=31;i>=0;i--)
       {
           if(((val>>i)&1) == 1)
           {
               if(p->right==NULL)
               {
                   Binary_Trie*temp = new Binary_Trie;
                   
                   p->right = temp;
               }
               
               p=p->right;
           }
           
           else{
               
               if(p->left==NULL)
               {
                   Binary_Trie*temp = new Binary_Trie;
                   
                   p->left = temp;
               }
               
               p=p->left;
           }
       }
   }
   
   
   int min_find(Binary_Trie*head,int x)
   {
       int res = 0;
       Binary_Trie*p = head;
       
       for(int i=31;i>=0;i--)
       {
           if(((x>>i)&1) == 1)
           {
               if(p->right==NULL)
               {
                   p=p->left;
                   res += pow(2,i);
               }
               
               else{
                   p=p->right;
               }
           }
           
           else{
               if(p->left==NULL)
               {
                   p=p->right;
                   res += pow(2,i);
               }
               
               else{
                   p=p->left;
               }
           }
       }
       
       return res;
   }
   
    int minxorpair(int n, int arr[]){    
        //code here
        
        
        if(n==1)
            return 0;
        
        if(n==2)
            return arr[0]^arr[1];
        
        
        Binary_Trie*head = new Binary_Trie();
        
        int min_res = INT_MAX;
        
        insert(head,arr[0]);
        for(int i=1;i<n;i++)
        {
            int res = min_find(head,arr[i]);
            
            min_res = min(res,min_res);
            insert(head,arr[i]);
        }
        
        return min_res;
    }
};
