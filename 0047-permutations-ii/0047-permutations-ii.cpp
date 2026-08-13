class Solution {
public:
    set<vector<int>>res;
    void rec(int i,vector<int>&nums){
        if(i==nums.size()){
            res.insert(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[j],nums[i]);
            rec(i+1,nums);
            swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       rec(0,nums);
       vector<vector<int>>ans;
       for(auto i:res)
       ans.push_back(i);
       return ans;
    }
};
