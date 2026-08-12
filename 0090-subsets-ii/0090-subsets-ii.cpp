class Solution {
public:
    vector<vector<int>>res;
    void rec(int i,vector<int>&temp,vector<int>&nums){
       res.push_back(temp);
       for(int j=i;j<nums.size();j++){
        if(j>i && nums[j]==nums[j-1]) continue;
        temp.push_back(nums[j]);
        rec(j+1,temp,nums);
        temp.pop_back();
       } 
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        rec(0,temp,nums);
        return res;
    }
};