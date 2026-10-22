class Solution {
public:
    bool check(vector<int>&nums, int ind){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[(i + ind) % n] != i)
            return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int res = INT_MAX;
        int n = nums.size();
        int ind = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                ind = i;
                break;
            }
        }
        if(check(nums,ind)){
            res = min(ind, 2 + n - ind);
        }
        reverse(nums.begin(),nums.end());
        ind = n - ind - 1;
        if(check(nums,ind)){
            res = min({res,ind + 1,1 + n - ind});
        }
        return res == INT_MAX ? -1 : res;
    }
};