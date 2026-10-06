#define ll long long
class Solution {
public:
    ll dp[17][2][2][17][17][17];
    ll rec(int i, int isStart, int tight, int last, int prev,int cnt,
           vector<int>& arr) {
        if (i >= arr.size())
            return cnt;
        if (dp[i][isStart][tight][last + 1][prev + 1][cnt] != -1)
            return dp[i][isStart][tight][last + 1][prev + 1][cnt];
        int bound = (tight == 1) ? arr[i] : 9;
        ll ans = 0;
        for (int j = 0; j <= bound; j++) {
            int newStart = (isStart || j != 0) ? 1 : 0;
            int newTight = (tight && j == arr[i]) ? 1 : 0;
            if (!newStart) {
                ans += rec(i + 1, newStart, newTight, -1, -1, cnt,  arr);
            } else if (newStart) {
                if (prev != -1 && last != -1 && ((last < prev && j < prev) ||
                    (last > prev && j > prev))) {
                    ans +=  rec(i + 1, newStart, newTight, prev, j, cnt + 1, arr);
                } else {
                    ans += rec(i + 1, newStart, newTight, prev, j, cnt, arr);
                }
            }
        }
        return dp[i][isStart][tight][last + 1][prev + 1][cnt] = ans;
    }
    long long totalWaviness(long long low, long long high) {
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
        ll ans1 = rec(0, 0, 1, -1, -1 ,0, arr2);
        memset(dp, -1, sizeof(dp));
        ll ans2 = rec(0, 0, 1, -1, -1, 0, arr1);
        return ans1 - ans2;
    }
};