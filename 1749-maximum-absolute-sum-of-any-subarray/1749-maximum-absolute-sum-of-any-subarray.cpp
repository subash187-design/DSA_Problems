class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curr1 = 0;
        int curr = 0;
        int res1 = 0;
        int res2 = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
           curr += nums[i];
           curr1 += nums[i];
           if(curr < 0)
           curr = 0;
           if(curr1 > 0)
           curr1 = 0;
           res1 = max(res1,curr);
           res2 = min(res2,curr1);
        }
        return max(abs(res2),abs(res1));
    }
};