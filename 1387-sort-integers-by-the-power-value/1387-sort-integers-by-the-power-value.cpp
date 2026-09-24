class Solution {
public:
    unordered_map<int,int>dp;
    int rec(int i) {
        if (i == 1) {
            return 0;
        }
        if (dp[i] != 0)
            return dp[i];
        int ans = 0;
        if (i % 2 == 0) {
            int temp = rec(i / 2);
            ans = 1 + temp;
        } else {
            int temp = rec(3 * i + 1);
            ans = 1 + temp;
        }
        return dp[i] = ans;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> ans;
        for (int i = lo; i <= hi; i++) {
            int res = rec(i);
            ans.push_back({i, res});
        }
        sort(ans.begin(), ans.end(), [](auto& a, auto& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        return ans[k-1].first;
    }
};