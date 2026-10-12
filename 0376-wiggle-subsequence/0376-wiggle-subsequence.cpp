class Solution {
public:
    int dp[1002][1002][3];
    int rec(int i, int prev, int toggle, vector<int>& nums) {
        if (i >= nums.size()) {
            return 0;
        }
        if (dp[i][prev + 1][toggle + 1] != -1)
            return dp[i][prev + 1][toggle + 1];
        int ans = 0;
        ans = max(ans, rec(i + 1, prev, toggle, nums));
        if (prev == -1) {
            ans = max(ans, rec(i + 1, nums[i], toggle, nums));
        } else if (toggle == -1) {
            if(nums[i] - prev > 0){
            ans = max(ans ,1 + rec(i + 1, nums[i], 1, nums));
            }
            else if(nums[i] - prev < 0){
                ans = max(ans ,1 + rec(i + 1, nums[i], 0, nums));
            }
        } else if (!toggle && nums[i] - prev > 0) {
            ans = max(ans,1 +  rec(i + 1, nums[i], 1 - toggle, nums));
        } else if (toggle && nums[i] - prev < 0) {
            ans = max(ans,1 +  rec(i + 1, nums[i], 1 - toggle, nums));
        }
        return dp[i][prev + 1][toggle + 1] =  ans;
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return rec(0, -1, -1, nums) + 1;
    }
};