class Solution {
public:
    int dp[15][2][2][2];
    int rec(int pos, int isStart, int tight, bool isChange, vector<int>& arr) {
        if (pos >= arr.size()) {
            if (isChange)
                return 1;
            return 0;
        }
        if (dp[pos][isStart][tight][isChange] != -1)
            return dp[pos][isStart][tight][isChange];
        int ans = 0;
        int bound = (tight == 1) ? arr[pos] : 9;
        for (int i = 0; i <= bound; i++) {
            int newStart = (isStart || i != 0) ? 1 : 0;
            int newTight = (tight && i == arr[pos]) ? 1 : 0;
            if (!newStart) {
                ans += rec(pos + 1, newStart, newTight, 0, arr);
            } else if (i == 3 || i == 4 || i == 7)
                continue;
            else {

                if (i == 2 || i == 5 || i == 6 || i == 9)
                    ans += rec(pos + 1, newStart, newTight, 1, arr);
                else
                    ans += rec(pos + 1, newStart, newTight, isChange, arr);
            }
        }
    return dp[pos][isStart][tight][isChange] = ans;
} int rotatedDigits(int n) {
    vector<int> arr;
    while (n) {
        arr.push_back(n % 10);
        n /= 10;
    }
    reverse(arr.begin(), arr.end());
    memset(dp, -1, sizeof(dp));
    return rec(0, 0, 1, 0, arr);
}
}
;