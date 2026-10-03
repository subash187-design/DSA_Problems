class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int rec(int i, int isMount, vector<int>& arr) {
        if (i >= arr.size()) {
            return 0;
        }
        if (dp[i][isMount] != -1)
            return dp[i][isMount];
        int ans = 1e9;
        if (i + 1 == n && isMount == 2)
            ans = 1;
        else if (!isMount && ((i + 1) < n) && arr[i] < arr[i + 1]) {
            int next = rec(i + 1, 1, arr);
            if (next != 1e9) {
                ans = 1 + next;
            }
        } else if ((isMount == 1) && (i + 1 < n) && arr[i] < arr[i + 1]) {
            int next = rec(i + 1, 1, arr);
            if (next != 1e9) {
                ans = 1 + next;
            }
        } else if ((isMount == 1) && (i + 1 < n) && arr[i] > arr[i + 1]) {
            int next = rec(i + 1, 2, arr);
            if (next != 1e9) {
                ans = 1 + next;
            }
        } else if ((isMount == 2) && (i + 1 < n) && arr[i] > arr[i + 1]) {
            int next = rec(i + 1, 2, arr);
            if (next != 1e9) {
                ans = 1 + next;
            }
        }
        else if(isMount == 2)
        ans = 1;
        return dp[i][isMount] = ans;
    }
    int longestMountain(vector<int>& arr) {
        n = arr.size();
        int res = 0;
        dp.resize(n, vector<int>(3, -1));
        for (int i = 0; i < n; i++) {
            int curr = rec(i, 0, arr);
            if (curr != 1e9)
                res = max(res, curr);
        }
        return res;
    }
};