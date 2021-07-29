struct TrieNode{
TrieNode* child[26]  // Can take 256 as well if want consider all character values (here we considered only a-z)
bool isEnd;
TrieNode()
{
isEnd = false;
for(int i=0;i<26;i++)
child[i] = NULL;

}
}
