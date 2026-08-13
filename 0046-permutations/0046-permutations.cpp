class Solution {
public:
    vector<vector<int>>res;
    void rec(int i,vector<int>&nums){
        if(i==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[j],nums[i]);
            rec(i+1,nums);
            swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       rec(0,nums);
       return res;
    }
};