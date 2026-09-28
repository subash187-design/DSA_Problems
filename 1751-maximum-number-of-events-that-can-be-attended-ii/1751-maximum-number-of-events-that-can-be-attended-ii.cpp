class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int binary(int i,vector<vector<int>>& events){
        int l = i;
        int r = n - 1;
        int k = events[i][1];
        int ans = n;
        while( l <= r){
            int mid = l + (r - l)/2;
            if(events[mid][0] > k){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    long long rec(int i,int k,vector<vector<int>>& events){
        if(i >= n || k < 1)
        return 0;
        if(dp[i][k] != -1)
        return dp[i][k];
        int next = binary(i,events);
        int take = events[i][2] + rec(next,k-1,events);
        int nottake = rec(i+1,k,events);
        return dp[i][k] =  max(take,nottake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
         n = events.size();
        sort(events.begin(),events.end(),[](auto &a,auto &b){
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        dp.resize(n,vector<int>(k+1,-1));
        return rec(0,k,events);
    }
};
