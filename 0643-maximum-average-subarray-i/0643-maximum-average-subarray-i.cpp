class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      int l=0;
      int r=0;
      int n=nums.size();
      int sum=0;
      double res=INT_MIN;
      for(r;r<n;r++){
        sum=sum+nums[r];
        if(r-l+1>k){
            sum-=nums[l];
            l++;
        }
        if(r-l+1==k){
            res=max(res,((sum*1.0)/(k)));
        }
      }  
      return res;
    }
};