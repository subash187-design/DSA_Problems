class Solution {
public:
    int dp[104];
    int rec(int i, vector<vector<int>>& clips, int time) {
        if (i >= clips.size())
            return 1e9;
        if(dp[i] != -1)
        return dp[i];
        int ans = 1e9;
        int start = clips[i][0];
        int end = clips[i][1];
        // cout << i << endl;
        for (int j = i + 1; j < clips.size(); j++) {
            if (clips[j][0] >= start && clips[j][0] <= end &&
                clips[j][1] >= time)
                ans = min(ans, 2);
            else if (clips[j][0] >= start && clips[j][0] <= end &&
                     clips[j][1] >= end)
                ans = min(ans, 1 + rec(j, clips, time));
        }
        return dp[i] = ans;
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), [](auto& a, auto& b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        int ans = 1e9;
        memset(dp,-1,sizeof(dp));
        for (int i = 0; i < clips.size(); i++) {
            if (clips[i][0] == 0)
             ans = min(ans, rec(i, clips, time));
            if (clips[i][0] == 0 && clips[i][1] >= time)
            return 1;
        }
        return ans >= 1e9 ? -1 : ans;
    }
};