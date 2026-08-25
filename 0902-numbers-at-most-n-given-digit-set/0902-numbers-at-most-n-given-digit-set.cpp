class Solution {
public:
    int dp[22][2][2];
    unordered_map<int, int> mp;
    int rec(int pos, int tight, int isStart, vector<string>& digits,
            vector<int>& arr) {
        if (pos >= arr.size())
            return isStart?1:0;
        if (dp[pos][tight][isStart] != -1)
            return dp[pos][tight][isStart];
        int ans = 0;
        int bound =
            (tight == 1) ? arr[pos] : 9; 
        for (int i = 0; i <= bound; i++) {
            if (mp.find(i) == mp.end() && !(!isStart && i==0))
                continue;
            int newStart = (isStart || i != 0) ? 1 : 0;
            int newTight = (tight && i == arr[pos]) ? 1 : 0;
            ans += rec(pos + 1, newTight, newStart, digits, arr);
        }
        return dp[pos][tight][isStart] = ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        memset(dp, -1, sizeof(dp));
        int temp = n;
        vector<int> arr;
        while (temp) {
            arr.push_back(temp % 10);
            temp = temp / 10;
        }
        for (string i : digits) {
            int x = stoi(i);
            mp[x] = 1;
        }
        reverse(arr.begin(), arr.end());
        return rec(0, 1, 0, digits, arr);
    }
};