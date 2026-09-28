class Solution {
public:
    int n ;
    vector<int>dp;
    int binary(int i,vector<vector<int>>& intervals){
        int l = i;
        int r = n - 1;
        int ans = n;
        int val = intervals[i][1];
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(intervals[mid][0] >= val){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    int rec(int i,vector<vector<int>>& intervals){
        if(i >= n)
        return 0;
        if(i == n-1)
        return 1;
        if(dp[i] != -1)
        return dp[i];
        int next = binary(i,intervals);
        int take = 1 + rec(next,intervals);
        int nottake = rec(i+1,intervals);
        return dp[i] = max(take,nottake);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            if(a[0] == b[0])
            return a[1] < b[1];
            return a[0] < b[0];
        });
        dp.resize(n,-1);
        int ans = rec(0,intervals);
        return n - ans;
    }
};