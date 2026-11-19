class Solution {
public:
    int minimizeSum(vector<int>& nums) {
       int n = nums.size();
       sort(nums.begin(),nums.end());
       if(n < 3){
        return 0;
       }
       int num1 = nums[0];
       int num2 = nums[1];
       int num3 = nums[n-1];
       int num4 = nums[n-2];
       
       return min({num3 - nums[2],nums[n - 3] - num1,num4 - num2});
    }
};