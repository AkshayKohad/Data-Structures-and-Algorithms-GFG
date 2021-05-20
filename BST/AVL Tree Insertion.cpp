class Solution{
  public:
  int Checkheight(Node*node)
  {
      if(node==NULL)
      return 0;
      
      return node->height;
  }
  
  Node *solution(Node*node, int data)
  {
      if(node==NULL)
      {
          Node*p = new Node(data);
          node=p;
          return node;
          
      }
      if(node->data>data)
     node->left = solution(node->left,data);
      
      else if(node->data<data){
          node->right = solution(node->right,data);
      }
      
      int lh = Checkheight(node->left);
      int rh = Checkheight(node->right);
      if(abs(lh-rh)>1)
      {
          if(node->left!=NULL && node->left->right!=NULL && node->data>data && node->left->data<data)
          {
                 Node*temp = node->left;
                 Node*temp1=temp->right;
              node->left = node->left->right->right;
              temp->right->right=node;
              
              temp->right=temp->right->left;
              temp1->left = temp;
              node=temp1;
              //node->height=node->height+1;
          
          }
          
          else if(node->right!=NULL && node->right->left!=NULL && node->data<data && node->right->data>data)
          {
              Node*temp = node->right;
               Node*temp1=temp->left;
              node->right=node->right->left->left;
              temp->left->left=node;
             
              temp->left=temp->left->right;
               temp1->right = temp;
               node=temp1;
                
          }
          
          else if(node->right!=NULL && node->right->right!=NULL && node->data<data && node->right->data<data)
          {
           Node*temp = node->right;
           node->right = node->right->left;
           temp->left = node;
           node=temp;
           
         
          }
          
          else if(node->left!=NULL && node->left->left!=NULL && node->data>data && node->left->data>data)
          {
           Node*temp = node->left;
           node->left = node->left->right;
           temp->right = node;
           node=temp;
           
            
          }
          
           node->left->height = max(Checkheight(node->left->left),Checkheight(node->left->right))+1;
           node->right->height = max(Checkheight(node->right->left),Checkheight(node->right->right))+1;
           node->height = max(node->right->height,node->left->height)+1;
      }
      else{
          node->height = max(lh,rh)+1;
      }
      return node;
  }
    /*You are required to complete this method */
    Node* insertToAVL(Node* node, int data)
    {
       
        //Your code here
       return solution(node,data);
    }
};
