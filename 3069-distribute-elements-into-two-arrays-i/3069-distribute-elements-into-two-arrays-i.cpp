class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
      vector<int>arr1,arr2;
      for(int i=0;i<nums.size();i++){
        if(arr1.size()==0)
        arr1.push_back(nums[i]);
        else if(arr2.size()==0)
        arr2.push_back(nums[i]);
        else{
            int n=arr1.size();
            int m=arr2.size();
            if(arr1[n-1]>arr2[m-1])
            arr1.push_back(nums[i]);
            else
            arr2.push_back(nums[i]);
        }
      }
      vector<int>res;
      for(int i:arr1)
      res.push_back(i);
      for(int i:arr2)
      res.push_back(i);
      return res;  
    }
};