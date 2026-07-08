class TrieNode{
    public:
        TrieNode *nxt[26];
        bool is_end;

        TrieNode(){
            is_end = false;
            for(int i = 0; i < 26; i++){
                nxt[i] = NULL;
            }
        }
};

class WordDictionary {
public:

    TrieNode *root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *cur = root;
        for(int i = 0; i < word.size(); i++){
            int imap = word[i] - 'a';
            if(cur->nxt[imap] == NULL) {
                cur->nxt[imap] = new TrieNode();
            }
            cur = cur->nxt[imap];
        }
        cur->is_end = true;
    }

    bool dfs(TrieNode *node, string &word, int pos){
        if(node == NULL) return false;

        if(pos == word.size()){
            return node->is_end;
        }

        if(word[pos] == '.'){
            for(int i = 0; i < 26; i++){
                if(dfs(node->nxt[i], word, pos + 1)){
                    return true;
                }
            }
            return false;
        }

        int imap = word[pos] - 'a';
        return dfs(node->nxt[imap], word, pos + 1);
        
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};
