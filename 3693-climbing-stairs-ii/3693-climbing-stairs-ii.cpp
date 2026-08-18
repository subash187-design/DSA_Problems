class Solution {
public:
    vector<int>dp;
    int rec(int i,int n,vector<int>&costs){
        if(i==n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int ans=INT_MAX;
        if(i+1<=n){
            ans=min(ans,rec(i+1,n,costs)+costs[i+1-1]+(((i+1)-i)*((i+1)-i)));
        }
        if(i+2<=n){
            ans=min(ans,rec(i+2,n,costs)+costs[i+2-1]+(((i+2)-i)*((i+2)-i)));
        }
        if(i+3<=n){
            ans=min(ans,rec(i+3,n,costs)+costs[i+3-1]+(((i+3)-i)*((i+3)-i)));
        }
        return dp[i]=ans;
    }
    int climbStairs(int n, vector<int>& costs) {
     dp.resize(n+1,-1);
     return rec(0,n,costs);   
    }
};