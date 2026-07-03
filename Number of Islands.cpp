class Solution {
public:

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool isValid(int r, int c, vector<vector<char>>& grid, 
                    vector<vector<bool>> &visited){
        int n = grid.size();
        int m = grid[0].size();
        if(r < 0 || r >= n || c < 0 || c >= m) return false;
        if(grid[r][c] == '0' || visited[r][c] == true) return false;
        return true;
    }

    void dfs(int r, int c, vector<vector<char>>& grid, 
                    vector<vector<bool>> &visited){
        visited[r][c] = true;
        for(int i = 0; i < 4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(isValid(nr, nc, grid, visited)) {
                dfs(nr, nc, grid, visited);
            }
        }   
    }
    int numIslands(vector<vector<char>>& grid) {

        if(grid.empty()) return 0;

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool> (col, false));
        int island = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    island++;
                    dfs(i, j, grid, visited);
                }
            }
        }

        return island;
    }
};
