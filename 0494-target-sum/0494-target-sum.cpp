class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int n=arr.size();
        int sm=accumulate(arr.begin(),arr.end(),0);
        int W=abs(target)+sm;
        if(W%2!=0) return 0;
        W=W/2;
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=W;j++){
                if(j<arr[i-1]){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
                }
            }
        }
        return dp[n][W];
    }
};