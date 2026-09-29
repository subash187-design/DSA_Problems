class Solution {
public:
    int dp[506][506];
    int rec(int i, int paid, vector<int>& cost, vector<int>& time) {
        if ((i >= cost.size() && paid >= cost.size()) || paid >= cost.size())
            return 0;
        if (i >= cost.size())
            return 1e9;
        if (dp[i][paid] != -1)
            return dp[i][paid];
        int ans = 1e9;
        ans = min(ans, rec(i + 1, paid, cost,time));
        ans = min(ans, cost[i] + rec(i + 1, paid + time[i] + 1, cost, time));
        return dp[i][paid] = ans;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, cost, time);
    }
};