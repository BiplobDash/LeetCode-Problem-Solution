class Solution {
public:
    struct Node{
        Node *nxt[26];
        string word;
        Node(){
            word = "";
            for(int i = 0; i < 26; i++) nxt[i] = NULL;
        }
    };
    Node *root;
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    vector<string> ans;

    void insert_trie(string word){
        Node *cur = root;
        for(int i = 0; i < word.size(); i++){
            int imap = word[i] - 'a';
            if(cur->nxt[imap] == NULL){
                cur->nxt[imap] = new Node();
            }
            cur = cur->nxt[imap];
        }
        cur->word = word;
    }
    void dfs(int r, int c, vector<vector<char>>& board, Node *node){
        
        char ch = board[r][c];
        int imap = ch - 'a';
        if(node->nxt[imap] == NULL) return;
        node = node->nxt[imap];

        if(node->word != ""){
            ans.push_back(node->word);
            node->word = "";
        }
        board[r][c] = '#';
        for(int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr < 0 || nc < 0 || nr >= board.size() || 
            nc >= board[0].size() || board[nr][nc] == '#') continue;
            dfs(nr, nc, board, node);
        }
        board[r][c] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        root = new Node();
        for(auto s : words){
            insert_trie(s);
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(i, j, board, root);
            }
        }
        return ans;
    }
};
