class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        ;
        queue<pair<int, int>> que;
        que.push({0, 0});
        vis[0][0] = 1;
        while (!que.empty()) {
            int i = que.front().first;
            int j = que.front().second;
            que.pop();
            if (i == n - 1 && j == m - 1)
                return true;
            if (grid[i][j] == 1) {
                int ltx = i;
                int lty = j - 1;
                if (ltx >= 0 && ltx < n && lty >= 0 && lty < m) {
                    if (grid[ltx][lty] == 1 || grid[ltx][lty] == 4 ||
                        grid[ltx][lty] == 6) {
                        if (!vis[ltx][lty]) {
                            vis[ltx][lty] = 1;
                            que.push({ltx, lty});
                        }
                    }
                }
                int rtx = i;
                int rty = j + 1;
                if (rtx >= 0 && rtx < n && rty >= 0 && rty < m) {
                    if (grid[rtx][rty] == 1 || grid[rtx][rty] == 3 ||
                        grid[rtx][rty] == 5) {
                        if (!vis[rtx][rty]) {
                            vis[rtx][rty] = 1;
                            que.push({rtx, rty});
                        }
                    }
                }
            } else if (grid[i][j] == 2) {
                int ltx = i - 1;
                int lty = j;
                if (ltx >= 0 && ltx < n && lty >= 0 && lty < m) {
                    if (grid[ltx][lty] == 2 || grid[ltx][lty] == 4 ||
                        grid[ltx][lty] == 3) {
                        if (!vis[ltx][lty]) {
                            vis[ltx][lty] = 1;
                            que.push({ltx, lty});
                        }
                    }
                }
                int rtx = i + 1;
                int rty = j;
                if (rtx >= 0 && rtx < n && rty >= 0 && rty < m) {
                    if (grid[rtx][rty] == 2 || grid[rtx][rty] == 6 ||
                        grid[rtx][rty] == 5) {
                        if (!vis[rtx][rty]) {
                            vis[rtx][rty] = 1;
                            que.push({rtx, rty});
                        }
                    }
                }
            } else if (grid[i][j] == 3) {
                int ltx = i;
                int lty = j - 1;
                if (ltx >= 0 && ltx < n && lty >= 0 && lty < m) {
                    if (grid[ltx][lty] == 1 || grid[ltx][lty] == 4 ||
                        grid[ltx][lty] == 6) {
                        if (!vis[ltx][lty]) {
                            vis[ltx][lty] = 1;
                            que.push({ltx, lty});
                        }
                    }
                }
                int rtx = i + 1;
                int rty = j;
                if (rtx >= 0 && rtx < n && rty >= 0 && rty < m) {
                    if (grid[rtx][rty] == 2 || grid[rtx][rty] == 6 ||
                        grid[rtx][rty] == 5) {
                        if (!vis[rtx][rty]) {
                            vis[rtx][rty] = 1;
                            que.push({rtx, rty});
                        }
                    }
                }
            } else if (grid[i][j] == 4) {
                int ltx = i;
                int lty = j + 1;
                if (ltx >= 0 && ltx < n && lty >= 0 && lty < m) {
                    if (grid[ltx][lty] == 1 || grid[ltx][lty] == 5 ||
                        grid[ltx][lty] == 3) {
                        if (!vis[ltx][lty]) {
                            vis[ltx][lty] = 1;
                            que.push({ltx, lty});
                        }
                    }
                }
                int rtx = i + 1;
                int rty = j;
                if (rtx >= 0 && rtx < n && rty >= 0 && rty < m) {
                    if (grid[rtx][rty] == 2 || grid[rtx][rty] == 6 ||
                        grid[rtx][rty] == 5) {
                        if (!vis[rtx][rty]) {
                            vis[rtx][rty] = 1;
                            que.push({rtx, rty});
                        }
                    }
                }
            } else if (grid[i][j] == 5) {
                int ltx = i - 1;
                int lty = j;
                if (ltx >= 0 && ltx < n && lty >= 0 && lty < m) {
                    if (grid[ltx][lty] == 2 || grid[ltx][lty] == 4 ||
                        grid[ltx][lty] == 3) {
                        if (!vis[ltx][lty]) {
                            vis[ltx][lty] = 1;
                            que.push({ltx, lty});
                        }
                    }
                }
                int rtx = i;
                int rty = j - 1;
                if (rtx >= 0 && rtx < n && rty >= 0 && rty < m) {
                    if (grid[rtx][rty] == 1 || grid[rtx][rty] == 4 ||
                        grid[rtx][rty] == 6) {
                        if (!vis[rtx][rty]) {
                            vis[rtx][rty] = 1;
                            que.push({rtx, rty});
                        }
                    }
                }
            } else if (grid[i][j] == 6) {
                int ltx = i - 1;
                int lty = j;
                if (ltx >= 0 && ltx < n && lty >= 0 && lty < m) {
                    if (grid[ltx][lty] == 2 || grid[ltx][lty] == 4 ||
                        grid[ltx][lty] == 3) {
                        if (!vis[ltx][lty]) {
                            vis[ltx][lty] = 1;
                            que.push({ltx, lty});
                        }
                    }
                }
                int rtx = i;
                int rty = j + 1;
                if (rtx >= 0 && rtx < n && rty >= 0 && rty < m) {
                    if (grid[rtx][rty] == 1 || grid[rtx][rty] == 3 ||
                        grid[rtx][rty] == 5) {
                        if (!vis[rtx][rty]) {
                            vis[rtx][rty] = 1;
                            que.push({rtx, rty});
                        }
                    }
                }
            }
        }
        return false;
    }
};