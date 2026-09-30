class Solution {
public:
    vector<vector<vector<int>>> dp;
    int n, m;
    int rec(int i, int j, int k, vector<vector<int>>& grid) {
        if (i == n - 1 && j == m - 1) {
            if (grid[i][j] == 0)
                return 0;
            else if (k > 0)
                return grid[i][j];
            return -1;
        }
        if (i >= n || j >= m) {
            return -1;
        }

        if (k < 0)
            return -1;

        if (dp[i][j][k] != -2)
            return dp[i][j][k];
        int ans = -1;

        if (grid[i][j] == 0) {
            int down = rec(i + 1, j, k, grid);
            int right = rec(i, j + 1, k, grid);
            int temp = max(down, right);
            ans = temp;

        } else {
            if (k > 0) {
                int down = rec(i + 1, j, k - 1, grid);
                int right = rec(i, j + 1, k - 1, grid);
                int temp = max(down, right);
                if (temp == -1)
                    ans = -1;
                else
                    ans = temp + grid[i][j];

            } else {
                ans = -1;
            }
        }

        return dp[i][j][k] = ans;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n, vector<vector<int>>(m, vector<int>(k + 1, -2)));
        return rec(0, 0, k, grid);
    }
};