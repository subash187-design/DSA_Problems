class Solution {
public:
    int dp[2004][52];
    int mod=1e9+7;
    int rec(int i,int prevInc,int prevDec,vector<int>&nums){
        if(i>=nums.size())
        return 1;
        if(dp[i][prevInc]!=-1)
        return dp[i][prevInc];
        int ans=0;
        int n=nums[i];
        for(int j=prevInc;j<=n;j++){
            if(nums[i]-j<=prevDec){
                ans=(ans+rec(i+1,j,nums[i]-j,nums))%mod;
            }
        }
        return dp[i][prevInc]=ans;
    }
    int countOfPairs(vector<int>& nums) {
      memset(dp,-1,sizeof(dp));
      return rec(0,0,51,nums);  
    }
};