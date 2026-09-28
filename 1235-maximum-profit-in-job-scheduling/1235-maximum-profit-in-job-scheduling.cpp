class Solution {
public:
    int n;
    vector<int> dp;
    int binary(int i, vector<vector<int>>& events) {
        int l = i;
        int r = n - 1;
        int k = events[i][1];
        int ans = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (events[mid][0] >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    int rec(int i, vector<vector<int>>& events) {

        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int next = binary(i, events);
        int take = events[i][2] + rec(next, events);
        int nottake = rec(i + 1, events);

        return dp[i] = max(take, nottake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        n = startTime.size();
        vector<vector<int>> events(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            events[i][0] = startTime[i];
            events[i][1] = endTime[i];
            events[i][2] = profit[i];
        }
        sort(events.begin(), events.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        dp.resize(n, -1);
        return rec(0, events);
    }
};
