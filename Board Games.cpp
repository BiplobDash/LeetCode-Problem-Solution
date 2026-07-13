/*

Given an M × N board of uppercase English letters and a dictionary 
containing a list of valid words, find all words from the dictionary 
that can be formed on the board.
A word can be formed by starting from any cell and moving to any of 
its 8 adjacent cells (horizontal, vertical, or diagonal) one character 
at a time.
A cell may be used at most once while forming a single word.
Return all dictionary words that can be found in the board.

Input:
vector<string> ans;
string words[] = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "SENS", "TUNES", "CAT"};
    char board[3][4] = {
        {'S', 'E', 'R', 'T'},
        {'U', 'N', 'K', 'S'},
        {'T', 'C', 'A', 'T'},
    };  

Output:
SNAKE SNACK SNACKS TUNES CAT

*/


#include<bits/stdc++.h>


struct TrieNode{
    TrieNode * nxt[26];
    string word;

    TrieNode(){
        word = "";
        for(int i = 0; i < 26; i++) nxt[i] = NULL;
    }
};

TrieNode *root;

void insertTrie(string word){
    TrieNode *cur = root;

    for(auto w : word){
        int imap = w - 'A';
        if(cur->nxt[imap] == NULL){
            cur->nxt[imap] = new TrieNode();
        }
        cur = cur->nxt[imap];
    }
    cur->word = word;
}

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1,  0,  1,-1, 1,-1, 0, 1};
vector<string> ans;
string words[] = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "SENS", "TUNES", "CAT"};
    char board[3][4] = {
        {'S', 'E', 'R', 'T'},
        {'U', 'N', 'K', 'S'},
        {'T', 'C', 'A', 'T'},
    };

void dfs(int r, int c, TrieNode *nood){

    char ch = board[r][c];
    int imap = board[r][c] - 'A';
    if(nood->nxt[imap] == NULL) return;

    nood = nood->nxt[imap];
    if(nood->word != ""){
        ans.push_back(nood->word);
        nood->word = "";
    }

    board[r][c] = '#';
    for(int k = 0; k < 8; k++){
        int nx = r + dx[k];
        int ny = c + dy[k];
        if(nx < 0 || nx >= 3 || ny < 0 || ny >= 4 || board[nx][ny] == '#') continue;
        dfs(nx, ny, nood);
    }
    board[r][c] = ch;
}

void Biplob_Dash() {

    root = new TrieNode();

    for(auto w : words){
        insertTrie(w);
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            dfs(i, j, root);
        }
    }

    for(auto s : ans){
        cout << s << endl;
    }
}

 

int32_t main(){


    fast();
    
    int tc = 1;
    // cin >> tc;
    
    for(int t = 1; t <= tc; t++){
        // cout << "Case " << t << ": ";
        Biplob_Dash();
    }
 
    return 0;
}