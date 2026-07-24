class Solution {
public:
    int bs(int l,int r,vector<int>& nums, int target){
        int ans=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){
                ans=m;
                r=m-1;
            }
            else if(nums[m]<target){
                l=m+1;
            }
            else
             r=m-1;
        }
        return ans;
    }
    int bs1(int l,int r,vector<int>& nums, int target){
        int ans=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){
                ans=m;
                l=m+1;
            }
            else if(nums[m]<target){
                l=m+1;
            }
            else
             r=m-1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int x=bs(l,r,nums,target);
        int y=bs1(l,r,nums,target);
        return {x,y};

    }
};