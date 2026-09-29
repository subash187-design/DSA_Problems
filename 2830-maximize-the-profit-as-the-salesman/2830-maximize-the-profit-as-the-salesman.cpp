class Solution {
public:
    vector<int>dp;
    int binary(int i,vector<vector<int>>& offers,int m){
        int l = i;
        int r = m - 1;
        int ans = m;
        int val = offers[i][1];
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(offers[mid][0] > val){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    int rec(int i,vector<vector<int>>&offers,int m){
        if(i >= m)
        return 0;
        if(dp[i] != -1)
        return dp[i];
        int next = binary(i,offers,m);
        int take = offers[i][2] + rec(next,offers,m);
        int nottake = rec(i+1,offers,m);
        return dp[i] = max(take,nottake);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end(),[](auto &a,auto &b){
            if(a[0] == b[0])
            return a[1] < b[1];
            return a[0] < b[0];
        });
        int m = offers.size();
        dp.resize(m,-1);
        return rec(0,offers,m);
    }
};