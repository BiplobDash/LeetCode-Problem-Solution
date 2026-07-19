class Solution {
public:

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int dfs(int r, int c, vector<vector<int>>& grid){
        int area = 1;
        grid[r][c] = 0;
        for(int k = 0; k < 4; k++){
            int nr = r + dx[k];
            int nc = c + dy[k];
            if(nr < 0 || nr >= grid.size() || 
                nc < 0 || nc >= grid[0].size() ||
                    grid[nr][nc] == 0) continue;
                
            area += dfs(nr, nc, grid);
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }

        return ans;
    }
};
