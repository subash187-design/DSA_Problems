class Solution {
public:
    int dp[504][504][3];
    int n, m;
    int rec(int i, int j, int k, vector<vector<int>>& coins) {
        if (i == n - 1 && j == m - 1) {
            if (coins[i][j] < 0) {
                if (k > 0)
                    return 0;
            }
            return coins[i][j];
        }
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        int ans = -1e9;
        if (coins[i][j] < 0) {
            if (k > 0) {
                if (i + 1 < n) {
                    ans = max(ans, rec(i + 1, j, k - 1, coins));
                    ans = max(ans, coins[i][j] + rec(i + 1, j, k, coins));
                }
                if (j + 1 < m) {
                    ans = max(ans, rec(i, j + 1, k - 1, coins));
                    ans = max(ans, coins[i][j] + rec(i, j + 1, k, coins));
                }
            } else {
                if (i + 1 < n) {
                    ans = max(ans, coins[i][j] + rec(i + 1, j, k, coins));
                }
                if (j + 1 < m) {
                    ans = max(ans, coins[i][j] + rec(i, j + 1, k, coins));
                }
            }
        } else {
            if (i + 1 < n) {
                ans = max(ans, coins[i][j] + rec(i + 1, j, k, coins));
            }
            if (j + 1 < m) {
                ans = max(ans, coins[i][j] + rec(i, j + 1, k, coins));
            }
        }
        return dp[i][j][k] = ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size();
        m = coins[0].size();
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 2, coins);
    }
};