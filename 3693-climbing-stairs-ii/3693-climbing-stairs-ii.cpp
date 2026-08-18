class Solution {
public:
    vector<int>dp;
    int rec(int i,int n,vector<int>&costs){
        if(i==n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int ans=INT_MAX;
        int k;
        if(i+1<=n){
            k=rec(i+1,n,costs)+costs[i+1-1]+(((i+1)-i)*((i+1)-i));
            ans=min(ans,k);
        }
        if(i+2<=n){
            k=rec(i+2,n,costs)+costs[i+2-1]+(((i+2)-i)*((i+2)-i));
            ans=min(ans,k);
        }
        if(i+3<=n){
            k=rec(i+3,n,costs)+costs[i+3-1]+(((i+3)-i)*((i+3)-i));
            ans=min(ans,k);
        }
        return dp[i]=ans;
    }
    int climbStairs(int n, vector<int>& costs) {
     dp.resize(n+1,-1);
     return rec(0,n,costs);   
    }
};