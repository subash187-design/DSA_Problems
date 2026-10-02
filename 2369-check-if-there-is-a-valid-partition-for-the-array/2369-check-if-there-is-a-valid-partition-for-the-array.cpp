class Solution {
public:
    vector<int>dp;
    int n;
    bool isValid(int l,int r,vector<int>&nums){
        if((r - l + 1) == 2){
            return nums[l] == nums[r];
        }
        else{
            int a = nums[l];
            int b = nums[l+1];
            int c = nums[r];
            if(a == b && a == c)
            return true;
            if( a + 1 == b && b + 1 == c)
            return true;
        }
        return false;
    }
    bool rec(int i,vector<int>& nums){
        if(i >= nums.size())
        return 1;
        if(dp[i] != -1)
        return dp[i];
        for(int j = i + 1; j < min(n , i + 3); j++){
            if(isValid(i,j,nums) && rec(j+1,nums)){
                return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        dp.resize(n,-1);
        return rec(0,nums);
    }
};