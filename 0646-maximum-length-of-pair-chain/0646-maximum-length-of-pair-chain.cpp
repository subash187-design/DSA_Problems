class Solution {
public:
    vector<int>dp;
    int binary(int i,vector<vector<int>>& pairs,int m){
        int l = i;
        int r = m - 1;
        int ans = m;
        int val = pairs[i][1];
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(pairs[mid][0] > val){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    int rec(int i,vector<vector<int>>&pairs,int m){
        if(i >= m)
        return 0;
        if(dp[i] != -1)
        return dp[i];
        int next = binary(i,pairs,m);
        int take = 1 + rec(next,pairs,m);
        int nottake = rec(i+1,pairs,m);
        return dp[i] = max(take,nottake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](auto &a,auto &b){
            if(a[0] == b[0])
            return a[1] < b[1];
            return a[0] < b[0];
        });
        int m = pairs.size();
        dp.resize(m,-1);
        return rec(0,pairs,m);
    }
};