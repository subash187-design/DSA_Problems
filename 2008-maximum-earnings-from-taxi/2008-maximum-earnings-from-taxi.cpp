class Solution {
public:
    vector<long long>dp;
    int binary(int i,vector<vector<int>>&rides, int n){
        int l = i;
        int r = n - 1;
        int val = rides[i][1];
        int ans = n;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(rides[mid][0] >= val){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    long long rec(int i,vector<vector<int>>& rides,int n){
        if(i >= n)
        return 0;
        if(dp[i] != -1)
        return dp[i];
        int next = binary(i,rides,n);
        int start = rides[i][0];
        int end = rides[i][1];
        int tip = rides[i][2];
        long long take = end - start + tip + rec(next,rides,n);
        long long nottake = rec(i+1,rides,n);
        return dp[i] = max(take,nottake);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end(),[](auto &a,auto &b){
            if(a[0] == b[0])
            return a[1] < b[1];
            return a[0] < b[0];
        });
        int m = rides.size();
        dp.resize(m,-1);
        return rec(0,rides,m);
    }
};