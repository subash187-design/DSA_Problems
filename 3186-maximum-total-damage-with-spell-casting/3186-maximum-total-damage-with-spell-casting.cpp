class Solution {
public:
    vector<long long>dp;
    map<int,long long>mp;
    int n;
    int binary(int i , int val, vector<int>& power){
        int l = i + 1;
        int r = n - 1;
        int ans = n;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(power[mid] > val){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    long long rec(int i,vector<int>& power){
        if(i >= n)
        return 0;
        if(dp[i] != -1)
        return dp[i];
        long long ans = 0;
        int next = binary(i,power[i]+2,power);
        ans = max(ans, rec(i+1,power));
        ans = max(ans,mp[power[i]] + rec(next,power));
        return dp[i] = ans;
    }
    long long maximumTotalDamage(vector<int>& power) {
        for(int i : power){
            mp[i] = mp[i] + i;
        }
        vector<int>newPower;
        for(auto it:mp){
            newPower.push_back(it.first);
        }
        n = newPower.size();
        dp.resize(n,-1);
        return rec(0,newPower);
    }
};