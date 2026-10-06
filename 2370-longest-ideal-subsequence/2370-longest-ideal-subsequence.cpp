class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int rec(int i,int prev, string& s,int k){
        if(i >= n)
        return 0;
        if(dp[i][prev + 1] != -1)
        return dp[i][prev + 1];
        int ans = 0;
        int curr = s[i] - 'a';
        if(prev == -1 || abs(prev - curr) <= k){
            ans = max(ans, 1 + rec(i + 1, curr, s, k));
        }
        ans = max(ans, rec(i + 1, prev , s, k));
        return dp[i][prev + 1] = ans;
    }
    int longestIdealString(string s, int k) {
         n = s.size();
         dp.resize(n,vector<int>(27,-1));
         return rec(0, -1, s, k);
    }
};