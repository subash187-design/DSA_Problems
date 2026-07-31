class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int r=0;
        int mn=INT_MAX;
        int sum=0;
        for(r;r<nums.size();r++){
            sum+=nums[r];
            while(sum>=target){
                mn=min(mn,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        return mn==INT_MAX?0:mn;

    }
};