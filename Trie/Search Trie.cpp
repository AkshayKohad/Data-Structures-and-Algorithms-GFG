TrieNode* root;
bool Search(string &key)
{
  TrieNode *curr = root;
  for(int i=0;i<key.length();i++)
  {
    int index = key[i] - 'a';
    if(curr->child[index]==NULL)
    {
      return false;
    }
    curr = curr->child[index];
  }
  return curr->isEnd;
}
