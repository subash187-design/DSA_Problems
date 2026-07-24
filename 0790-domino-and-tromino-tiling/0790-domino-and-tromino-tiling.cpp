class Solution {
public:
   long long dp[1004];
   int mod=1e9+7;
   int rec(int n){
    if(n==0 || n==1 || n==2) 
    return n;
    if(n==3) return 5;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=(1ll*(rec(n-1)*2)%mod+rec(n-3))%mod;
    
   }
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(n);
    }
};