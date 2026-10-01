class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int mod = 1e9 + 7;
    int rec(int i , int steps){
        if(steps == 0 && i == 0)
        return 1;
        if(steps < 0 || i >= n || i < 0)
        return 0;
        if(dp[i][steps] != -1)
        return dp[i][steps];
        int ans = 0;
        ans = (ans + rec(i + 1,steps - 1)) % mod;
        ans = (ans + rec(i - 1,steps - 1)) % mod;
        ans = (ans + rec(i ,steps - 1)) % mod;
        return dp[i][steps] = ans;
    }
    int numWays(int steps, int arrLen) {
        n = arrLen;
        dp.resize(501,vector<int>(steps+1,-1));
        return rec(0,steps);
    }
};