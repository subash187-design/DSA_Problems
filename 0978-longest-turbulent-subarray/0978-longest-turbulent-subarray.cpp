class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int rec(int i, int k, vector<int>& arr) {
        if (dp[i][k] != -1)
            return dp[i][k];
        int ans = 0;
        if ((i + 1) < n) {
            if (k == 0) {
                if (i % 2 && arr[i] > arr[i + 1]) {
                    ans = 1 + rec(i + 1, k, arr);
                } else if (i % 2 == 0 && arr[i] < arr[i + 1]) {
                    ans = 1 + rec(i + 1, k, arr);
                }
            } else {
                if (i % 2 && arr[i] < arr[i + 1]) {
                    ans = 1 + rec(i + 1, k, arr);
                } else if (i % 2 == 0 && arr[i] > arr[i + 1]) {
                    ans = 1 + rec(i + 1, k, arr);
                }
            }
        }
        return dp[i][k] = ans;
    }
    int maxTurbulenceSize(vector<int>& arr) {
        n = arr.size();
        dp.resize(n, vector<int>(2, -1));
        int res = 0;
        for (int i = 0; i < n; i++) {
            int ans1 = rec(i, 0, arr);
            int ans2 = rec(i, 1, arr);
            res = max(res, max(ans1, ans2));
        }
        return res + 1;
    }
};