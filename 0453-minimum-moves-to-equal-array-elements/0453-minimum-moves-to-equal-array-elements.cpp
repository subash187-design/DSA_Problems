class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int mn = *min_element(nums.begin(), nums.end());
        for (int i : nums)
         ans += (i - mn);
        return ans;
    }
};