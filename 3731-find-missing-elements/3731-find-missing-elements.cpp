class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
      int i=*min_element(nums.begin(),nums.end());
      int j=*max_element(nums.begin(),nums.end());
      unordered_map<int,int>mp;
      for(int k:nums)
       mp[k]++;
      vector<int>res;
      for(i;i<=j;i++){
        if(mp[i]==0)
        res.push_back(i);
      }  
      return res;
    }
};