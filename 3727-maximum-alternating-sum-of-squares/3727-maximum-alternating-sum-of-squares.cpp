class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
       for(int i = 0; i < nums.size();i++)
       nums[i] = abs(nums[i]);
       sort(nums.begin(),nums.end());
       int n = nums.size();
       int even = (n + 2 - 1) / 2; 
       int odd = n - even;
       long long res = 0;
       for(int i = 0; i < odd; i++){
        res -= (nums[i] * nums[i]);
       }
       for(int i = odd; i < n; i++){
        res += (nums[i] * nums[i]);
       }
       return res;

    }
};