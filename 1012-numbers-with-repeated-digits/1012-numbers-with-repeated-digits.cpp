class Solution {
public:
    int dp[32][2][2][32657];
    int rec(int pos, int tight, int isStart, int mask, vector<int>& arr) {
        if (pos == arr.size()) {
            return 1;
        }
        if (dp[pos][tight][isStart][mask] != -1)
            return dp[pos][tight][isStart][mask];
        int ans = 0;
        int bound = (tight == 1) ? arr[pos] : 9;
        for (int i = 0; i <= bound; i++) {
            if ((mask >> i) & 1)
                continue;
            int newStart = (isStart == 1 || i != 0) ? 1 : 0;
            int newTight = (tight == 1 && i == bound) ? 1 : 0;
            int newMask = mask;
            if (newStart)
                newMask = newMask | (1 << i);
            ans += rec(pos + 1, newTight, newStart, newMask, arr);
        }
        return dp[pos][tight][isStart][mask] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        memset(dp, -1, sizeof(dp));
        vector<int> arr;
        int temp = n;
        while (temp) {
            arr.push_back(temp % 10);
            temp = temp / 10;
        }
        reverse(arr.begin(), arr.end());
        int nonRepeat = rec(0, 1, 0, 0, arr);
        
        return n + 1 - nonRepeat;
    }
};