class Solution {
public:
    vector<vector<vector<int>>>dp;
    int mod=1e9+7;
    int rec(int n,int absent,int late){
        if(n==0)
        return 1;
        if(dp[n][absent][late]!=-1)
        return dp[n][absent][late];
        long long ans=0;
        if(late<2){
            ans=(ans+rec(n-1,absent,late+1))%mod;
        }
        if(absent==0){
            ans=(ans+rec(n-1,1,0))%mod;
        }
        ans=(ans+rec(n-1,absent,0))%mod;
        return dp[n][absent][late]=ans;
    }
    int checkRecord(int n) {
        dp.resize(n+1,vector<vector<int>>(3,vector<int>(4,-1)));
        return rec(n,0,0);
    }
};