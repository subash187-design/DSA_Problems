class Solution {
public:
    vector<vector<int>>res;
    void rec(vector<int>&temp,unordered_map<int,int>mp,vector<int>&nums){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==0){
                mp[nums[i]]=1;
                temp.push_back(nums[i]);
                rec(temp,mp,nums);
                mp[nums[i]]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       unordered_map<int,int>mp;
       vector<int>temp;
       rec(temp,mp,nums);
       return res;
    }
};