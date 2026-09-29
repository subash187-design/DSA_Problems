class Solution {
public:
    int dp[54][1004];
    int mod = 1e9 + 7;
    int rec(int i,int target,vector<vector<int>>&types){
        if(target == 0)
        return 1;
        if(i >= types.size())
        return 0;
        if(dp[i][target] != -1)
        return dp[i][target];
        int ans = 0;
        int curr = 0;
        ans = (ans + rec(i+1, target ,types)) % mod;
        for(int j = 0;j < types[i][0]; j++){
            curr += types[i][1];
            if((target - curr) >= 0){
                ans = (ans + rec(i+1,target - curr,types)) % mod;
            }
            else{
                break;
            }
        }
        return dp[i][target] = ans;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        memset(dp,-1,sizeof(dp));
        return rec(0,target,types);
    }
};