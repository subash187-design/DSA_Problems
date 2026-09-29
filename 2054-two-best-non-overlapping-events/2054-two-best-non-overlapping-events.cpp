class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int binary(int i,vector<vector<int>>& events){
        int l = i;
        int r = n - 1;
        int ans = n;
        int val = events[i][1];
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(events[mid][0] > val){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    int rec(int i,int k,vector<vector<int>>&events){
        if( i >= n || k < 1)
        return 0;
        if(dp[i][k] != -1)
        return dp[i][k];
        int next = binary(i,events);
        int take = events[i][2] + rec(next,k-1,events);
        int nottake = rec(i+1,k,events);
        return dp[i][k] = max(take,nottake);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),[](auto &a,auto &b){
            if(a[0] == b[0])
            return a[1] < b[1];
            return a[0] < b[0];
        });
        n = events.size();
        dp.resize(n,vector<int>(3,-1));
        return rec(0,2,events);
    }
};