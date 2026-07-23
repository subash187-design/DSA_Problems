class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amt + 1, 0));

        for (int i = 1; i <= amt; i++) {
            dp[0][i] = 1e9;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amt; j++) {
                if (j < coins[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
            }
        }

        return dp[n][amt] >= 1e9 ? -1 : dp[n][amt];
    }
};