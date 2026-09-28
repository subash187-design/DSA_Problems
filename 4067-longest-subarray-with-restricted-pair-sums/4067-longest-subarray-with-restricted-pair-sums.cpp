class Solution {
public:
    bool check(int l,int r,vector<int>&nums){
        vector<int>freq(501,0);
        for(int i = l;i <= r; i++){
            freq[nums[i]]++;
        }
        for(int i = 1; i <= 500; i++){
            if(freq[i] == 0) continue;
            freq[i]--;
            for(int j = 1;j <= 500 ; j++){
                if(freq[j] == 0) continue;
                freq[j]--;
                int sum = i + j;
                if(sum <= 500 && freq[sum] != 0)
                return true;
                freq[j]++;
            }
            freq[i]++;
        }
        return false;
    }
    int maxSubarray(vector<int>& nums) {
        int res = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        for(r ; r < n ; r++){
            while(check(l,r,nums)){
                l++;
            }
            res = max(res,r - l + 1);
        }
        return res;
    }
};