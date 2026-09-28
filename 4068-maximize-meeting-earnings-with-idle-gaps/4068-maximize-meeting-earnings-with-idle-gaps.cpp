class Solution {
public:
    int n;
    vector<vector<long long>>dp;
    int binary(int i,vector<vector<int>>& meetings){
        int l = i;
        int r = n - 1;
        int k = meetings[i][1];
        int ans = n;
        while( l <= r){
            int mid = l + (r - l)/2;
            if(meetings[mid][0] >= k){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    long long rec(int i,int k,vector<vector<int>>& meetings){
        if(i >= n)
        return 0;
        if(dp[i][k] != -1)
        return dp[i][k];
        int nxt = binary(i,meetings);
        long long nottake = rec(i+1,k,meetings);
        long long res = 0;
        if(k == 0){
            long long first = meetings[i][2];
            long long next = rec(nxt,1,meetings) + (meetings[i][2] - meetings[i][1]);
            res = max(res,max(first,next));
        }
        else if(k == 1){
            long long last = meetings[i][2] + meetings[i][0];
            long long next = rec(nxt,1,meetings) + (meetings[i][0] + meetings[i][2] - meetings[i][1]);
            res = max(res,max(last,next));
        }
        return dp[i][k] = max(res,nottake);
    }
    long long maxEarnings(vector<vector<int>>& meetings) {
        n = meetings.size();
        sort(meetings.begin(),meetings.end(),[](auto &a,auto &b){
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        dp.resize(n,vector<long long>(2,-1));
        return rec(0,0,meetings);
    }
};