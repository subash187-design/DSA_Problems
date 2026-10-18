#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<ll>> dp;
    ll rec(int i, int n, int k) {
        if (i >= n) {
            return k == 0;
        }
        if (dp[i][k] != -1)
            return dp[i][k];
        ll ans = 0;
        if (k > 0)
            ans = (ans + rec(i + 1, n, k - 1)) % mod;
        ans = (ans + rec(i + 1, n, k)) % mod;
        return dp[i][k] = ans;
    }
    ll solve(vector<int>& nums) {
        if (nums.size() <= 2)
            return 1;
        vector<int> left;
        vector<int> right;
        int k = nums[0];
        int n = nums.size();
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < k)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }
        int l = left.size();
        for (int i = 0; i <= n; i++) {
            fill(dp[i].begin(), dp[i].begin() + l + 2, -1);
        }
        ll ans = rec(0, n - 1, l);
        ll lt = solve(left);
        ll rt = solve(right);
        ll res = (((ans * lt) % mod) * rt) % mod;
        return res;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        dp.resize(1004, vector<ll>(1004, -1));
        ll ans = solve(nums);
        return (ans - 1 + mod) % mod;
    }
};