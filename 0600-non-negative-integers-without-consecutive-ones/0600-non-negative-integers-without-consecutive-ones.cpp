class Solution {
public:
    int dp[33][2][2][2];
    int rec(int i, int isStart, int tight, int isOne, vector<int>& arr) {
        if (i >= arr.size())
            return 1;
        if (dp[i][isStart][tight][isOne] != -1)
            return dp[i][isStart][tight][isOne];
        int bound = 1;
        if (tight == 1)
            bound = arr[i];
        int ans = 0;
        for (int j = 0; j <= bound; j++) {
            if (isOne && j == 1)
                continue;
            int newStart = (isStart == 1 || j == 1) ? 1 : 0;
            int newTight = (tight == 1 && j == bound) ? 1 : 0;
            if (j == 1)
                ans += rec(i + 1, newStart, newTight, 1, arr);
            else
                ans += rec(i + 1, newStart, newTight, 0, arr);
        }
        return dp[i][isStart][tight][isOne] = ans;
    }
    int findIntegers(int n) {
        vector<int> arr;
        while (n) {
            arr.push_back(n % 2);
            n = n / 2;
        }
        memset(dp, -1, sizeof(dp));
        reverse(arr.begin(), arr.end());
        return rec(0, 0, 1, 0, arr);
    }
};