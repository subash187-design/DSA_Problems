class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int n, m;
    void dfs1(int i, int j, vector<vector<int>>& vis,
              vector<vector<int>>& grid) {
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int x = dx[k] + i;
            int y = dy[k] + j;
            if (x >= 0 && x < n && y >= 0 && y < m) {
                if (grid[x][y] == 0 && !vis[x][y]) {
                    dfs1(x, y, vis, grid);
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    vis[i][j] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0 && !vis[i][0]) {
                dfs1(i, 0, vis, grid);
            }
            if(grid[i][m-1]==0 && !vis[i][m-1]){
                dfs1(i, m - 1, vis, grid);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 0 && !vis[0][i]) {
                dfs1(0, i, vis, grid);
            }
            if (grid[n - 1][i] == 0 && !vis[n - 1][i]) {
                dfs1(n - 1, i, vis, grid);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    dfs1(i, j, vis, grid);
                    res++;
                }
            }
        }
        return res;
    }
};