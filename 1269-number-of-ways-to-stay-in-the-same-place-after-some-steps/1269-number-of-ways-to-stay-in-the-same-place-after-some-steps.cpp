class Solution {
public:
    unordered_map<string,int>dp;
    int n;
    int mod = 1e9 + 7;
    int rec(int i , int steps){
        if(steps == 0 && i == 0)
        return 1;
        if(steps < 0 || i >= n || i < 0)
        return 0;
        string temp = to_string(i) + "#" + to_string(steps);
        if(dp.find(temp) != dp.end())
        return dp[temp];
        int ans = 0;
        ans = (ans + rec(i + 1,steps - 1)) % mod;
        ans = (ans + rec(i - 1,steps - 1)) % mod;
        ans = (ans + rec(i ,steps - 1)) % mod;
        return dp[temp] = ans;
    }
    int numWays(int steps, int arrLen) {
        n = arrLen;
        return rec(0,steps);
    }
}; 