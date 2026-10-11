class Solution {
public:
    int dp[3001];
    int rec(int sum, int num, int k) {
        if (sum == num) {
            return 0;
        }
        if (sum > num) {
            return 1e9;
        }
        if(dp[sum] != -1)
        return dp[sum];
        int ans = 1e9;
        for (int i = k; i <= num; i += 10) {
            int temp = rec(sum + i, num, k);
            if (temp != 1e9)
                ans = min(ans,1 + temp);
        }
        return dp[sum] = ans;
    }
    int minimumNumbers(int num, int k) {
        if (num == 0)
            return 0;
        if(k == 0){
            if(num % 10 == 0)
            return 1;
            else
            return -1;
        }
        memset(dp,-1,sizeof(dp));
        int ans = rec(0, num, k);
        if (ans == 1e9)
            return -1;
        return ans;
    }
};