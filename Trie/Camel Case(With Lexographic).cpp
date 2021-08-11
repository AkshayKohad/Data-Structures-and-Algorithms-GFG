struct TrieNode
{
	TrieNode* children[ALPHABET_SIZE];

	// isLeaf is true if the node represents
	// end of a word
	bool isLeaf;

	// vector to store list of complete words
	// in leaf node
	vector<string> word;
};

// Returns new Trie node (initialized to NULLs)
TrieNode* getNewTrieNode(void)
{
	TrieNode* pNode = new TrieNode;

	if (pNode)
	{
		pNode->isLeaf = false;

		for (int i = 0; i < ALPHABET_SIZE; i++)
			pNode->children[i] = NULL;
	}

	return pNode;
}

//Function to insert word into the Trie.
void insert(TrieNode* root, string word)
{
	int index;
	TrieNode* pCrawl = root;

	for (int level = 0; level < word.length(); level++)
	{
		//considering only uppercase characters.
		if (islower(word[level]))
			continue;

		//getting current character position.
		index = int(word[level]) - 'A';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNewTrieNode();

		pCrawl = pCrawl->children[index];
	}

	//marking last node as leaf.
	pCrawl->isLeaf = true;

	//pushing word into vector associated with leaf node.
	(pCrawl->word).push_back(word);
}

//Function to print all children of Trie node root.
void printAllWords(TrieNode* root)
{
	//if current node is leaf.
	if (root->isLeaf)
	{
		sort((root->word).begin(), (root->word).end());
		for(string str : root->word)
			cout << str<<" ";
	}

	//recursing for all children of root node.
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		TrieNode* child = root->children[i];
		if (child)
			printAllWords(child);
	}
}

//Function to search for pattern in Trie.
bool search(TrieNode* root, string pattern)
{
	int index;
	TrieNode* pCrawl = root;

	for (int level = 0; level < pattern.length(); level++)
	{
		index = int(pattern[level]) - 'A';
		// Invalid pattern
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	//printing all words matching that pattern.
	printAllWords(pCrawl);

	return true;
}


class Solution
{
    public:
    //Function to print all words in the CamelCase dictionary 
    //that matches with a given pattern.
    void findAllWords(vector<string> dict, string pattern)
    {
    	//constructing Trie root node.
    	TrieNode* root = getNewTrieNode();
    
    	//constructing Trie from given dict.
    	for (string word : dict)
    		insert(root, word);
    
    	//searching for pattern in Trie.
    	if (!search(root, pattern))
    		cout << "No match found";
    }
};
