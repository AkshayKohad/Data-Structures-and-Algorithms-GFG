class Solution{
  public:
  
   bool isEmpty(trie_node_t*root)
  {
      for(int i=0;i<26;i++)
      {
          if(root->children[i]!=NULL)
          return false;
      }
      
      return true;
  }
  
  trie_node_t *solution(trie_node_t *root,char key[],int i)
  {
      if(root==NULL)return NULL;
      if(key[i]=='\0')
      {
        root->value = 0;
        if(isEmpty(root) == true)
        {
            delete(root);
            root=NULL;
        }
        
        return root;
      }
      
      int index = key[i]-'a';
      root->children[index] = solution(root->children[index],key,i+1);
      
      if(isEmpty(root) && root->value==0)
      {
          delete(root);
          root=NULL;
      }
      
      return root;
  }
  
 
  
  void deleteKey(trie_node_t *root, char key[])
  {
    //Code here
    root = solution(root,key,0);
  }
};
