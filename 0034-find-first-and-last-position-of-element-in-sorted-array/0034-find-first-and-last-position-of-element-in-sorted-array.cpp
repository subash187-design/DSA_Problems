class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      if(nums.size()==0) return{-1,-1};
       auto it=lower_bound(nums.begin(),nums.end(),target);
       auto it1=upper_bound(nums.begin(),nums.end(),target);
       int x=-1;
       int y=-1;
       if(it!=nums.end() && target==*it){
        x=it-nums.begin();
       }
       int a=it1-nums.begin();
       if(a-1>=0 && a-1<nums.size() && target==nums[a-1])
       y=a-1;
       return {x,y};
    }
};