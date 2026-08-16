class Solution {
public:
    int dp[2004];
    int rec(int target,vector<int>&nums){
        if(target<0)
         return 0;
        if(target==0) 
        return 1;
        if(dp[target]!=-1)
        return dp[target];
        int ans=0;
        
        for(int j=0;j<nums.size();j++){
            if(nums[j]<=target){
                ans+=rec(target-nums[j],nums);
            }
        }
        return dp[target]=ans;

    }
    int combinationSum4(vector<int>& nums, int target) {
     memset(dp,-1,sizeof(dp));
     return rec(target,nums);   
    }
};