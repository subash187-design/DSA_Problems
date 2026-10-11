class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) {
        int n = nums.size();
        vector<int> pre(n), suff(n);
        pre[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                pre[i] = 1 + pre[i - 1];
            } else {
                pre[i] = 0;
            }
        }
        suff[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                suff[i] = 1 + suff[i + 1];
            } else {
                suff[i] = 0;
            }
        }
        vector<int>res;
        for(int i = time ;i < n - time ; i++){
            if(i == 0 || i == n - 1){
                res.push_back(i);
                continue;
            }
            int lh = pre[i];
            int rh = suff[i];
            if(lh >= time && rh >= time)
            res.push_back(i);
        }
        return res;
    }
};