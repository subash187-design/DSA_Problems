class Solution {
public:
    int dp[8004][1004];
    int mod = 1e9 + 7;
    int rec(int curr,int k,int endPos){
        if(curr == endPos && k == 0){
            return 1;
        }
        if(k < 0)
        return 0;
        if(dp[curr + 4000][k] != -1)
        return dp[curr + 4000][k];
        int ans = 0;
        ans = (ans + rec(curr + 1, k - 1,endPos)) % mod;
        ans = (ans + rec(curr - 1, k - 1, endPos)) % mod;
        return dp[curr + 4000][k] = ans;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        return rec(startPos,k,endPos);
    }
};