class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int minFlips(vector<vector<int>>& mat) {
        queue<tuple<int, int, int, int, vector<vector<int>>>> que;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int k = (i * m) + j;
                int mask = 0;
                que.push({i, j, 0, mask | (1 << k), mat});
            }
        }
        while (!que.empty()) {
            auto [i, j, steps, mask, grid] = que.front();
            que.pop();
            bool flag = true;
            for (int i = 0; i < n; i++) {
                bool temp = false;
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 1) {
                        temp = true;
                        break;
                    }
                }
                if (temp) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return steps;
            grid[i][j] = 1 - grid[i][j];
            for (int k = 0; k < 4; k++) {
                int x = dx[k] + i;
                int y = dy[k] + j;
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    grid[x][y] = 1 - grid[x][y];
                }
            }
            flag = true;
            for (int i = 0; i < n; i++) {
                bool temp = false;
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 1) {
                        temp = true;
                        break;
                    }
                }
                if (temp) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return steps + 1;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    int k = (x * m) + y;
                    if (!(mask & (1 << k))) {
                        que.push({x, y, steps + 1, mask | (1 << k), grid});
                    }
                }
            }
        }
        return -1;
    }
};