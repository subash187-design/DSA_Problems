class Solution {
public:
    int minCostClimbingStairs(vector<int>& arr) {
        int n=arr.size();
        if(n==0)
        return 0;
        if(n==1)
        return arr[0];
        if(n==2)
        return min(arr[0],arr[1]);
        int dp[n];
        dp[0]=arr[0];
        dp[1]=arr[1];
        for(int i=2;i<n;i++){
            dp[i]=arr[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};