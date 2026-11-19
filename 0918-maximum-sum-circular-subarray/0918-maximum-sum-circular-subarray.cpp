class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int res = 0;
       int curr = 0;
       int res1 = -1e9;
       int curr1 = 0;
       int tot = accumulate(nums.begin(),nums.end(),0);
       for(int i = 0;i < nums.size(); i++){
        curr += nums[i];
        curr1 += nums[i];
        //cout<<curr<<" "<<curr1<<endl;
        if(curr > nums[i])
        curr = nums[i];
        res = min(res,curr);
        if(curr1 < nums[i])
        curr1 = nums[i];
        res1 = max(res1,curr1);
        //cout<<curr<<" "<<curr1<<endl;
       } 
       if((tot - res) == 0)
       return res1;
       return max(tot - res,res1);
    }
};