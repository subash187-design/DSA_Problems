#define ll long long
class Solution {
public:
    ll dp[17][2][2][400][17];
    ll rec(int i, int isStart, int tight, int balance, int cnt,
           vector<int>& arr) {
        if (i >= arr.size()) {
            if (cnt <= 1)
                return 0;
            if (balance == 0)
                return 1;
            return 0;
        }
        if (dp[i][isStart][tight][balance + 200][cnt] != -1)
            return dp[i][isStart][tight][balance + 200][cnt];
        int bound = (tight == 1) ? arr[i] : 9;
        ll ans = 0;
        for (int j = 0; j <= bound; j++) {
            int newStart = (isStart || j != 0) ? 1 : 0;
            int newTight = (tight && j == arr[i]) ? 1 : 0;
            int newBalance = balance;

            if (!newStart) {
                ans += rec(i + 1, newStart, newTight, balance, cnt, arr);
            } else {
                if ((cnt % 2) == 0) {
                    newBalance -= j;
                } else {
                    newBalance += j;
                }
                ans += rec(i + 1, newStart, newTight, newBalance, cnt + 1, arr);
            }
        }
        return dp[i][isStart][tight][balance + 200][cnt] = ans;
    }
    long long countBalanced(long long low, long long high) {
        vector<int> arr1, arr2;
        low = low - 1;
        while (low) {
            arr1.push_back(low % 10);
            low /= 10;
        }
        while (high) {
            arr2.push_back(high % 10);
            high /= 10;
        }
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        memset(dp, -1, sizeof(dp));
        ll ans1 = rec(0, 0, 1, 0, 0, arr2);
        memset(dp, -1, sizeof(dp));
        ll ans2 = rec(0, 0, 1, 0, 0, arr1);
        return ans1 - ans2;
    }
};