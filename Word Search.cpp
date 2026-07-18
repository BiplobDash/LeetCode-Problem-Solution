class Solution {
public:

    struct TrieNode{
        string word = "";
        unordered_map<char, TrieNode*> nxt;
    };

    TrieNode *root;
    void insert_trie(string word){
        TrieNode *cur = root;
        for(auto c : word){
            if(cur->nxt.find(c) == cur->nxt.end()){
                cur->nxt[c] = new TrieNode();
            }
            cur = cur->nxt[c];
        }
        cur->word = word;
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool dfs(int r, int c, TrieNode *node, 
        vector<vector<char>>& board, string &word
        ){

        char ch = board[r][c];
        if(node->nxt.find(ch) == node->nxt.end()) return false;

        node = node->nxt[ch];
        if(node->word == word) return true;

        board[r][c] = '#';

        for(int k = 0; k < 4; k++){

            int nr = r + dx[k];
            int nc = c + dy[k];

            if(nr < 0 || nr >= board.size() ||
                nc < 0 || nc >= board[0].size() || board[nr][nc] == '#'){
                    continue;
                }
                
            if (dfs(nr, nc, node, board, word)) {
                board[r][c] = ch;
                return true;
            }

        }

        board[r][c] = ch;
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        
        root = new TrieNode();

        insert_trie(word);

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(dfs(i, j, root, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};
