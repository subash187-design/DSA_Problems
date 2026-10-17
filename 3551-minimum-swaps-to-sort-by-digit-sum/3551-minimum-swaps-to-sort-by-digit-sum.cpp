class Solution {
public:
    int res = 0;
    void solve(vector<int>& nums, vector<int>& dup) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            mp[nums[i]] = i;
        for(int i = 0 ;i < n ; i++){
            if(dup[i] != nums[i]){
                int k = mp[dup[i]];
                swap(nums[i],nums[k]);
                mp[nums[i]] = i;
                mp[nums[k]] = k;
                res++;
            }
        }
       
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>arr(n);
        for (int i = 0; i < n; i++) {
            int temp = nums[i];
            int sum = 0;
            while (temp) {
                sum += (temp % 10);
                temp /= 10;
            }
            arr[i] = {sum, nums[i]};
        }
        sort(arr.begin(), arr.end(),[](auto &a, auto& b){
            if(a.first == b.first)
            return a.second < b.second;
            return a.first < b.first;
        });
        vector<int>dup(n,0);
        for(int i = 0; i < n ;i++){
            dup[i] = arr[i].second;
        }
        // for(int i : dup)
        // cout<<i<<" ";
        solve(nums, dup);
        return res;
    }
};