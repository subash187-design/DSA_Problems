class Solution {
public:
    int findMin(vector<int>& nums) {
      int l=0;
      int r=nums.size()-1;
      while(l<r){
        int m=l+(r-l)/2;
        if(nums[l]>nums[m]){
            r=m;
        }
        else if(nums[m]>nums[r]){
            l=m+1;
        }
        else
        return nums[l];
      }  
      return nums[l];
    }
};